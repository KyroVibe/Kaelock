#include "util/Vec4.hpp"

Vec4::Vec4(): _x(0.0), _y(0.0), _z(0.0), _w(0.0) { }

Vec4::Vec4(float x, float y, float z, float w): _x(x), _y(y), _z(z), _w(w) { }

Vec4::~Vec4() { }

std::string Vec4::to_string() {
    std::stringstream ss;
    ss << "(" << _x << ", " << _y << ", " << _z << ", " << _w << ")";
    return ss.str();
}
