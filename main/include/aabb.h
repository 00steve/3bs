#ifndef UTILS_AABB_H
#define UTILS_AABB_H

#include "i2.h"

class AABB {
private:


public:
    AABB();
    AABB(int xMin,int yMin,int xMax,int yMax);

    i2 max;
    i2 min;
    
};

#endif