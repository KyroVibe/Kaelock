#ifndef _BRATVA_UTIL_VEC4
#define _BRATVA_UTIL_VEC4

#include <string>
#include <sstream>

class Vec4 {
private:
    float _x, _y, _z, _w;
public:
    Vec4();
    Vec4(float x, float y, float z, float w);
    ~Vec4();

    std::string to_string();
};

#endif
