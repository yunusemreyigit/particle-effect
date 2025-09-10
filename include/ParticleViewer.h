//
// Created by yey on 11.06.2025.
//

#ifndef PARTICLEVIEWER_H
#define PARTICLEVIEWER_H

#include <vector>

#include "shader.h"
#include "Particle.h"

class ParticleViewer {
public:
  ParticleViewer();
  void render(const std::vector<Particle>& particles);
  void init();
  void draw();
  glm::mat4 getModelMatrix();
  glm::mat4 getViewMatrix();
  glm::mat4 getProjectionMatrix();
private:
  Shader particleShader;
  glm::mat4 modelMatrix {};
  glm::mat4 viewMatrix {};
  glm::mat4 projectionMatrix {};
};



#endif //PARTICLEVIEWER_H
