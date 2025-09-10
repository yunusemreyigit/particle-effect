//
// Created by yey on 02.07.2025.
//

#ifndef INPUT_H
#define INPUT_H

#include "Window.h"

class Input {
private:
  GLFWwindow* window;
public:
  Input(GLFWwindow* window);
  void processInput();

};



#endif //INPUT_H
