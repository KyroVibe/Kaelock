#version 430

layout(std430, binding = 3) buffer RenderData {
    vec4 colors[];
};

out vec4 out_Color;

void main() {
    vec4 index = gl_FragCoord + vec4(0.5f, 0.5f, 0, 0);
    index = vec4(index.x * 0.999f, index.y * 0.999f, 0, 1);
    out_Color = colors[(16 * int(16 * index.y)) + int(16 * index.x)];
}
