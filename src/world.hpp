#pragma once

#include "constants.hpp"
#include "gfx.hpp"

namespace goat::world {

/**
 * @brief Contains position, rotation, and scaling information for an object
 */
struct Transform {
    vec3 pos = vec3(0.0f, 0.0f, 0.0f);
    vec3 rot = vec3(0.0f, 0.0f, 0.0f);
    vec3 scale = vec3(1.0f, 1.0f, 1.0f);
    std::shared_ptr<Transform *> parent = nullptr;
    std::vector<std::shared_ptr<Transform *>> children{};

    // Return the x vector relative to the object
    constexpr inline vec3 right() const;
    // Return the y vector relative to the object
    constexpr inline vec3 forward() const;
    // Return the z vector relative to the object
    constexpr inline vec3 up() const;
};

/**
 * @brief The `GameObject` struct binds all of the information necessary
 *        to render an object to the screen. This includes the VAO, VBO, EBO,
 *        drawing details, and transformation information.
 */
struct GameObject {
    bool active = true;
    vec3 world_pos = vec3(0.0f, 0.0f, 0.0f);
    const gfx::ObjectLifetime lifetime = gfx::ObjectLifetime::SCENE;
    const std::shared_ptr<Transform> transform{};

    static inline std::shared_ptr<GameObject> create(
        vec3 world_pos = vec3(0.0f, 0.0f, 0.0f), gfx::ObjectLifetime lifetime = gfx::ObjectLifetime::SCENE,
        std::shared_ptr<Transform> transform = std::shared_ptr<Transform>(new Transform()), bool active = true) {
        return std::make_shared<GameObject>(GameObject{
            .active = active,
            .world_pos = world_pos,
            .lifetime = lifetime,
            .transform = transform,
        });
    }
    // Return if the object is rendered using EBO/indices instead of VBO/vertices
    constexpr inline bool hasEBO() const;
    // Return the model matrix for the object taking its transformations into account
    constexpr inline glm::mat4 getModelMatrix() const;
    // Apply texture details to related shader uniforms
    inline void applyUniformData() const;
};

/**
 * @brief A scene contains a collection of objects that are rendered to the screen
 *        using a given camera and render context.
 */
struct Scene {
    const std::shared_ptr<gfx::RenderContext> render_context;
    const std::shared_ptr<camera::Camera> camera;
    std::vector<std::shared_ptr<GameObject>> objects{};
    std::string name = "Scene";

    static inline Scene *create(
        const std::string &name, std::shared_ptr<camera::Camera> camera,
        std::shared_ptr<gfx::RenderContext> context = std::shared_ptr<gfx::RenderContext>(new gfx::RenderContext()),
        std::vector<std::shared_ptr<GameObject>> objects = std::vector<std::shared_ptr<GameObject>>()) {
        return new Scene{
            .name = name,
            .render_context = context,
            .camera = camera,
            .objects = objects,
        };
    }

    inline void use() const {
#ifdef __DEBUG__
        LOG(DEBUG) << "Scene<" << this->name << ">::use()";
#endif

        this->render_context->compile();
        this->render_context->use();
    }

    inline void render() const {
        assert(this->render_context != nullptr);

#ifdef __DEBUG__
        LOG(INFO) << "Scene<" << this->name << ">::render() BEGIN";
        auto timeStart = std::chrono::high_resolution_clock::now();
#endif
        this->use();

        const float *projection = static_cast<const float *>(glm::value_ptr(this->camera->getProjectionMatrix()));
        this->render_context->setMatrix("projection", projection, 4);

        const float *view = static_cast<const float *>(glm::value_ptr(this->camera->view));
        this->render_context->setMatrix("view", view, 4);

#ifdef __DEBUG__
        LOG(DEBUG) << "\tProjection = [x=" << projection[0] << ", y=" << projection[1] << ", z=" << projection[2]
                   << ", w=" << projection[3] << "]";
        LOG(DEBUG) << "\t      View = [x=" << view[0] << ", y=" << view[1] << ", z=" << view[2] << ", w=" << view[3]
                   << "]";
#endif
        for (auto object : this->objects) {
            if (object != nullptr) {
                auto model = static_cast<const float *>(glm::value_ptr(object->getModelMatrix()));
                this->render_context->setMatrix("model", model, 4);
                this->render_context->render(this->camera.get());
            }
        }
#ifdef __DEBUG__
        auto obj_count = this->objects.size();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart);
        LOG(INFO) << "Scene<" << this->name << ">::render() [" << duration.count() << "μs] " << obj_count << " objects";
#endif
    }
};

struct World {};

}  // namespace goat::world

#include "world_gameobject.inl"
#include "world_transform.inl"