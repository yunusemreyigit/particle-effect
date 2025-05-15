#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std;

constexpr int WIDTH = 800, HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Particle Simulation!", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create GLFW window." << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) < 0) {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }
    glViewport(0, 0, WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.83, 0.31, 0.32, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}