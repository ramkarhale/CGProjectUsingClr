#include "pch.h"
#include "SPMathTolerance.h"
#include<cmath>

SPMathTolerance::SPMathTolerance()
{
    _epsilon = 1E-6;      // Dont hard core this valaue ,set from application setting.
}
bool SPMathTolerance::IsZero(double value)
{
    return (fabs(value) <= _epsilon);
}
bool SPMathTolerance:: IsEqual(double value1, double value2)
{
    if (value1 == NULL && value2 == NULL)
    {
        throw 505;
    }
    return (fabs(value1 - value2) <= _epsilon);
}

bool SPMathTolerance::IsGreaterThan(double value1, double value2)
{
    return ((value1 - value2) > _epsilon); 
}

bool SPMathTolerance::IsLessThan(double value1, double value2)
{
    return ((value1 - value2) < _epsilon);
}

bool SPMathTolerance::IsPoint2Dequal(SPMathPoint2D point1, SPMathPoint2D point2)
{
    if (point1.GetXCoordinate() == point2.GetXCoordinate() && point1.GetYCoordinate() == point2.GetYCoordinate())
        return true;
    else
        return false;

}

bool SPMathTolerance::IsSPMathPintNull(double x, double y)
{
    if (x == NULL && y == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

