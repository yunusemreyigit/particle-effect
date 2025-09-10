#version 330 core
layout (location = 0) in vec3 Pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 FragPos;

void main(){
    gl_Position = projection * view * model * vec4(Pos, 1.0);
    FragPos = vec4(model * vec4(Pos, 1.0));
}