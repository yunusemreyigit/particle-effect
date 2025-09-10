//
// Created by yey on 11.06.2025.
//

#include "ParticleController.h"
#include <glm/ext/matrix_transform.hpp>
#include "Particle.h"

ParticleController::ParticleController()
{
    particleViewer = std::make_unique<ParticleViewer>();
}
ParticleViewer* ParticleController::getView(){
    return particleViewer.get();
}
void ParticleController::createParticles(const int particleNumber)
{
    // for (int i =0; i < particleNumber; i++)
    // {
    //     particles.emplace_back();
    // }
    particles.push_back(Particle(glm::vec3(.5f, .0, .0)));
    particles.push_back(Particle(glm::vec3(-.5f, .2, .0)));
}

void ParticleController::update(const float deltaTime)
{
    for (Particle& particle : particles)
    {
        particle.update(deltaTime);
    }
    particleViewer->render(particles);
}

void ParticleController::move(Particle particle, const glm::vec3 pos) const {
    // particle.changePosition(pos);
    // particle.changeModelMatrix();
    // particleViewer->update(particle.getModelMatrix());
}

void ParticleController::apply(Particle particle, glm::mat4 to, const float &deltaTime) const {
    // particle.decreaseLifetime(deltaTime);
    // particle.changeModelMatrix();
    // particleViewer->update(particle.getModelMatrix());
}
