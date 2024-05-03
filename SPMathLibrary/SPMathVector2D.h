#pragma once
#include "SPMathLine2D.h"
class SPMathVector2D
{
private:
	double m_vec_x_coord;
	double m_vec_y_coord;

public:
	// Constructors 
	SPMathVector2D();
	SPMathVector2D(double x, double y);
	void CreateSPMathVector2DFromSPAndEP(SPMathPoint2D StartPoint, SPMathPoint2D EndPoint);
	void CreateSPMathVector2DFromLine(SPMathLine2D line);
	void CreateSPMathVector2DFromPoint(SPMathPoint2D point);
	// Get set methods 
	double GetVecXCoordinate();
	double GetVecYCoorinate();
	// Member functions 
	double GetCrossProduct(SPMathVector2D vector);
	double GetDotProduct(SPMathVector2D vector);
	double GetMagnitude();
	double Distance(SPMathVector2D vector);
};

