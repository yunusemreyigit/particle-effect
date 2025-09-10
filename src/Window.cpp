//
// Created by yey on 02.07.2025.
//
#include "Window.h"

Window::Window(int width, int height): WIDTH(width), HEIGHT(height) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(WIDTH, HEIGHT, "Particle System", NULL, NULL);
  if (!window) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window,
    [](GLFWwindow* window, const int width, const int height) { glViewport(0,0,width,height); });

  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
     std::cout << "Failed to initialize GLAD" << std::endl;
  }
  glViewport(0, 0, WIDTH, HEIGHT);
}

GLFWwindow* Window::getWindow() const
{
  return window;
}

bool Window::shouldClose() const
{
  return glfwWindowShouldClose(window);
}
