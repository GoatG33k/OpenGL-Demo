#include "Scene.hpp"

#include "world/GameObject.hpp"

namespace goat::world {

Scene *Scene::create(
    const std::string &name,
    std::shared_ptr<world::Camera> camera,
    std::shared_ptr<gfx::RenderContext> context,
    std::vector<std::shared_ptr<GameObject>> objects) {
    return new Scene{
      .render_context = context,
      .camera = camera,
      .objects = objects,
      .name = name,
    };
}

void Scene::use() const {
#ifdef __DEBUG__
    LOG(DEBUG) << "Scene<" << this->name << ">::use()";
#endif

    if (!this->render_context->isCompiled()) this->render_context->compile();
    this->render_context->use();
}

void Scene::render() const {
    assert(this->render_context != nullptr);
    auto timeStart = std::chrono::high_resolution_clock::now();
    this->use();

    this->render_context->setMatrix("projection", this->camera->getProjectionMatrix().raw, 4);
    this->render_context->setMatrix("view", this->camera->view.raw, 4);
#ifdef __DEBUG__
    LOG(DEBUG) << "\tProjection = [x=" << projection[0] << ", y=" << projection[1]
               << ", z=" << projection[2] << ", w=" << projection[3] << "]";
    LOG(DEBUG) << "\t      View = [x=" << view[0] << ", y=" << view[1] << ", z=" << view[2]
               << ", w=" << view[3] << "]";
#endif

    for (const auto &object : this->objects) {
        if (object != nullptr) {
            this->render_context->setMatrix("model", object->getModelMatrix().raw, 4);
            this->render_context->render();
        }
    }
    auto obj_count = this->objects.size();
    auto timeEnd = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart);
    LOG(INFO) << "Scene<" << this->name << ">::render() [" << duration.count() << "μs] "
              << obj_count << " objects";
}

}  // namespace goat::world