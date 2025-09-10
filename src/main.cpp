#include <iostream>
#include <vector>

#include "Particle.h"
#include "shader.h"
#include "ParticleViewer.h"
#include "ParticleController.h"
#include "Window.h"
#include "Input.h"
#include <GLFW/glfw3.h>

constexpr int WIDTH = 600, HEIGHT = 600;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

GLFWwindow* window;
int main() {
    Window window(WIDTH, HEIGHT);
    Input input(window.getWindow());

    int particleNumber = 1;
    ParticleController particleController;

    particleController.createParticles(particleNumber);
    particleController.getView()->init();

    while (!window.shouldClose()) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        input.processInput();

        glClearColor(0.83, 0.31, 0.32, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        particleController.update(deltaTime);

        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
