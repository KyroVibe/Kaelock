#version 150 core

// out vec4 outColor;
varying vec2 uv_coord;
varying vec2 tiling_out;
in vec3 fColor;

void main() {
    // gl_FragColor = vec4(fColor, 1);

    vec2 tileCoord = vec2((uv_coord.x * tiling_out.x) - floor(uv_coord.x * tiling_out.x), (uv_coord.y * tiling_out.y) - floor(uv_coord.y * tiling_out.y));
    // vec2 tileCoord = vec2(uv_coord.x, uv_coord.y);
    // tileCoord = vec2(tileCoord.x / sqrt(2), tileCoord.y / sqrt(2));

    float blend = ((tileCoord.x + tileCoord.y) / 2) * sqrt(2);
    vec4 color = mix(vec4(1, 0, 0, 1), vec4(0, 0, 1, 1), blend);
    color = vec4(color.x * color.x, color.y * color.y, color.z * color.z, 1);

    // gl_FragColor = color;

    bool a = tileCoord.x > 0.5;
    a = a ^^ tileCoord.y > 0.5;
    if (a)
        gl_FragColor = vec4(1, 0, 1, 1);
    else
        gl_FragColor = vec4(0.1, 0.1, 0.1, 1);
}
