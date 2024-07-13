# OpenGL-Demo

A personal implementation of the [LearnOpenGL.com](https://learnopengl.com) tutorial, as I learn C++ for the first time as well (_please forgive me_).

## Dependencies
- GLI
- GLM
- GLAD generated headers
- easylogging++
- ImgUI
- OpenGL Headers (Khronos Group)

## Features

- [x] The lone polygon represents all of my suffering thus far 
- [x] Windows, macOS, and Linux support
- [x] Somewhat organized and safely-conscious code
- [ ] OpenGL Basics
  - [x] MSAA
  - [x] GLSL Shaders
  - [x] VAO / VBO / EBO
  - [x] Textures
  - [x] Transformations
  - [-] Coordinate System
  - [-] Camera
- [ ] Lighting
  - [ ] Colors
  - [ ] Basic Lighting
  - [ ] Materials
  - [ ] Lighting Maps
  - [ ] Light Casters
  - [ ] Multiple Lights
- [ ] Model Loading
  - [ ] Assimp
  - [ ] Mesh
  - [ ] Model
- [ ] Advanced OpenGL
  - [ ] Depth testing
  - [ ] Stencil testing
  - [ ] Blending
  - [ ] Face culling
  - [ ] Framebuffers
  - [ ] Cubemaps


## Development

```sh
# Generate the Makefile
cmake .

# Compile & run
make && ./GameDemo