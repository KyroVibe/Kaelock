#version 150

attribute uint textureId;
attribute vec2 tile;
attribute vec4 row0;
attribute vec4 row1;
attribute vec4 row2;
attribute vec4 row3;

out vec2 tiling_in;
out mat4 quad_transform;

void main() {
    gl_Position = vec4(0, 0, 0, 1);
    tiling_in = tile;
    quad_transform = mat4(row0, row1, row2, row3);
//    quad_transform[0] = vec4(row0.x, row1.x, row2.x, row3.x);
//    quad_transform[1] = vec4(row0.y, row1.y, row2.y, row3.y);
//    quad_transform[2] = vec4(row0.z, row1.z, row2.z, row3.z);
//    quad_transform[3] = vec4(row0.w, row1.w, row2.w, row3.w);
}
