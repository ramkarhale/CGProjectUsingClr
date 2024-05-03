#pragma once
#include "SPMathPoint2D.h"
class SPMathTolerance
{
private:
    double _epsilon;
public:


    SPMathTolerance();
    bool IsZero(double value);
    bool IsEqual(double value1, double value2);
    bool IsGreaterThan(double value1, double value2);
    bool IsLessThan(double value1, double value2);
    bool IsPoint2Dequal(SPMathPoint2D point1, SPMathPoint2D point2);
    bool IsSPMathPintNull(double x, double y);
 
};

