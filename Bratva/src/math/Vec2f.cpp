#include "math/MathTypes.hpp"

template<typename T>
Vec2f vec_xy(T val) {
    return { val.x, val.y };
}

template<typename T>
Vec2f vec_yz(T val) {
    return { val.y, val.z };
}

Vec4f mat_c0(Mat4x4f val) {
    return { val.mat[0], val.mat[1], val.mat[2], val.mat[3] };
}
Vec4f mat_c1(Mat4x4f val) {
    return { val.mat[4], val.mat[5], val.mat[6], val.mat[7] };
}
Vec4f mat_c0(Mat4x4f val) {
    return { val.mat[8], val.mat[9], val.mat[10], val.mat[11] };
}
Vec4f mat_c0(Mat4x4f val) {
    return { val.mat[12], val.mat[13], val.mat[14], val.mat[15] };
}
