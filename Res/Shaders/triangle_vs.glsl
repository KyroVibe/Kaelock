#version 150

attribute vec4 a_position;
attribute vec4 a_color;

out vec4 color;

void main() {
    color = a_color;
    gl_Position = a_position;
}
