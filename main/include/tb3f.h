#ifndef TB3Fheader
#define TB3Fheader

#include <Arduino.h>
#include <cmath>

class TB3F {
private:

public:
    double x;
    double y;
    double z;

    TB3F();
    
    TB3F(double x, double y, double z);

    double Length();
    TB3F Normalized();
    String ToString();


    /*operators*/
    TB3F& operator = (const TB3F& set);
    TB3F& operator += (const TB3F& add);
    TB3F& operator *= (const double& scale);
    TB3F& operator *= (const TB3F& mult);
    TB3F operator * (const TB3F& scale);
    TB3F operator * (const double& scale);
    TB3F operator / (const TB3F& div);
    TB3F operator / (const double& div);
    TB3F operator - (const TB3F& minus);

};

#endif