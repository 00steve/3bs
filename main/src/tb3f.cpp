#include "../include/tb3f.h"

TB3F::TB3F() : 
    x(0),
    y(0),
    z(0)
        {
}

TB3F::TB3F(double x, double y, double z) : 
    x(x),
    y(y),
    z(z)
        {
}

double TB3F::Length(){
    return std::sqrt(x*x + y*y + z*z);
}

TB3F TB3F::Normalized(){
    double len = Length();
    return TB3F(x / len, y / len, z / len);
}

String TB3F::ToString(){
    return "(" + String(x,10) + "," + String(y,10) + "," + String(z,10) + ")";
}


/*operators*/
TB3F& TB3F::operator = (const TB3F& set){
    x = set.x;
    y = set.y;
    z = set.z;
    return *this;
}

TB3F& TB3F::operator += (const TB3F& add){
    x += add.x;
    y += add.y;
    z += add.z;
    return *this;
}

TB3F& TB3F::operator *= (const double& scale){
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
}

TB3F& TB3F::operator *= (const TB3F& mult){
    x *= mult.x;
    y *= mult.y;
    z *= mult.z;
    return *this;
}

TB3F TB3F::operator * (const TB3F& mult){
    return TB3F(x * mult.x, y * mult.y, z * mult.z);
}

TB3F TB3F::operator * (const double& scale){
    return TB3F(x * scale, y * scale, z * scale);
}

TB3F TB3F::operator / (const TB3F& div){
    return TB3F(x / div.x, y / div.y, z / div.z);
}

TB3F TB3F::operator / (const double& div){
    return TB3F(x / div, y / div, z / div);
}


TB3F TB3F::operator - (const TB3F& minus){
    return TB3F(x - minus.x, y - minus.y, z - minus.z);
}