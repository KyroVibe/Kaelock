#version 430

layout (local_size_x = 16, local_size_y = 9) in;

//in uvec3 gl_NumWorkGroups;
//in uvec3 gl_WorkGroupID;
//in uvec3 gl_LocalInvocationID;
//in uvec3 gl_GlobalInvocationID;
//in uint  gl_LocalInvocationIndex;

layout(std430, binding = 3) buffer RenderData {
    vec4 colors[];
};

void main() {

    vec2 tileCoord = vec2(float(gl_WorkGroupID.x) / 16.0f, float(gl_WorkGroupID.y) / 9.0f);
    float blend = ((tileCoord.x + tileCoord.y) / 2) * sqrt(2);
    vec4 color = mix(vec4(1, 0, 0, 1), vec4(0, 0, 1, 1), blend);
    color = vec4(color.x * color.x, color.y * color.y, color.z * color.z, 1);

    colors[(gl_WorkGroupID.y * gl_NumWorkGroups.x) + gl_WorkGroupID.x] = color;
}
