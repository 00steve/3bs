#include "../include/aabb.h"

AABB::AABB(){
    min = i2(0,0);
    max = i2(0,0);
}

AABB::AABB(int xMin,int yMin,int xMax,int yMax){
    min.x = xMin;
    min.y = yMin;
    max.x = xMax;
    max.y = yMax;
}