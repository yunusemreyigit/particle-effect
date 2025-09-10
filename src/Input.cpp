//
// Created by yey on 02.07.2025.
//

#include "Input.h"

Input::Input(GLFWwindow* _window):window(_window){}

void Input::processInput() {
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
