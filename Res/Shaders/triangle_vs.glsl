#version 150

attribute vec4 a_position;
attribute vec4 a_color;

out vec4 color;

uniform float rotation;

void main() {
    color = a_color;

    mat4 rotMat = mat4(
         cos(rotation), sin(rotation), 0.0, 0.0,
        -sin(rotation), cos(rotation), 0.0, 0.0,
                   0.0,           0.0, 0.0, 0.0,
                   0.0,           0.0, 0.0, 1.0
    );

    gl_Position = a_position * rotMat;
    // gl_Position = a_position;
}
