#pragma once
#include<list>
#include "SPMathPoint2D.h"
#include "SPMathLine2D.h"

class SPMathBox2D
{
	private:
		SPMathPoint2D m_MinPoint;
		SPMathPoint2D m_MaxPoint;

	public:
		// Constructors 
		SPMathBox2D();
		SPMathBox2D(SPMathPoint2D point1,SPMathPoint2D point2);
		SPMathBox2D(SPMathLine2D line);
		bool IsTwoBoxIntersect(SPMathLine2D line1, SPMathLine2D line2);
		bool IsBoxIntersect(SPMathBox2D box);
		/*SPMathBox2D(list<SPMathLine2D> lineList);*/

};

