//
// Created by yey on 11.06.2025.
//
#include "glad/glad.h"
#include "ParticleViewer.h"

#include <Particle.h>

#include "shader.h"
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

unsigned int VAO;

ParticleViewer::ParticleViewer()
: particleShader("../shaders/particle.vs", "../shaders/particle.fs"),
    viewMatrix(glm::mat4(1.0f)), projectionMatrix(glm::mat4(1.0f)), modelMatrix(glm::mat4(1.0f)){

    particleShader.use();
    particleShader.setMat4("view", viewMatrix);
    particleShader.setMat4("model", modelMatrix);
    particleShader.setMat4("projection", projectionMatrix);
}

void ParticleViewer::render(const std::vector<Particle>& particles) {
    particleShader.use();
    // hareket ettir
    // döndür
    // scale et
    std::vector<glm::mat4> transformationMatricies{};
    for (auto particle : particles)
    {
        glBindVertexArray(VAO);
        glm::mat4 transformation{glm::mat4(1.0)};
        transformation = glm::translate(transformation, particle.getPosition());
        transformation = glm::scale(transformation, glm::vec3(particle.getSize()));

        // transformationMatricies.push_back(transformation);
        modelMatrix = transformation;
        particleShader.setMat4("model", transformation);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // particle.
    }

}
glm::mat4 ParticleViewer::getModelMatrix() {
    return modelMatrix;
}
glm::mat4 ParticleViewer::getViewMatrix() {
    return viewMatrix;
}
glm::mat4 ParticleViewer::getProjectionMatrix() {
    return projectionMatrix;
}
void ParticleViewer::draw(){
    // particleShader.use();
    // glBindVertexArray(VAO);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void ParticleViewer::init(){
    float particleVertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
        };

    unsigned int particleIndexes[] = {
        3, 2, 1, 3, 1, 0
        };
    unsigned int VBO, EBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &EBO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(particleVertices), particleVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(particleIndexes), particleIndexes, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}