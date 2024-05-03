#pragma once
#include "SPMathPoint2D.h"
//#include"SPMathVector2D.h"
class SPMathLine2D
{
private :
	SPMathPoint2D m_StartPoint;
	SPMathPoint2D m_EndPoint;

	double PLUSINFINITY = 1E25;
	double MINUSINFINITY = -1E25;

public:
	// Constructor,s and destructor
	SPMathLine2D();
	SPMathLine2D(SPMathPoint2D startPoint, SPMathPoint2D endPoint);
	//SPMathLine2D(SPMathLine2D& objLineCopy);

	// get set methods 
	SPMathPoint2D GetStartPoint();
	SPMathPoint2D GetEndPoint();

	void  SetStartPoint(SPMathPoint2D startPoint);
	void  SetEndPoint(SPMathPoint2D endPoint);

	// operator overloading

	//Method's or functions
	bool IsEqual(SPMathLine2D testLine);
	bool IsPointOnLine(SPMathPoint2D testPoint);

	double GetSlope();
	bool IsParallelTo(SPMathLine2D line);
	bool IsTwoLinePerpendicular(SPMathLine2D line);
	double Orientation(SPMathPoint2D testPoint);
	double Direction(SPMathPoint2D testPoint);
	bool SegmentIntersect(SPMathLine2D line);
	SPMathPoint2D* IntersectionPoint(SPMathLine2D line);
};

