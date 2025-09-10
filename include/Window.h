//
// Created by yey on 02.07.2025.
//

#ifndef WINDOW_H
#define WINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

class Window {
private:
    int WIDTH = 600, HEIGHT = 800;
    GLFWwindow* window;
public:
    Window(int width, int height);
    GLFWwindow* getWindow() const;
    bool shouldClose() const;

};
#endif //WINDOW_H
