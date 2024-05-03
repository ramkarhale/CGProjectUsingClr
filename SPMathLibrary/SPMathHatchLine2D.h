#pragma once
#include "SPMathLine2D.h"
#include<vector>
using namespace std;
class SPMathHatchLine2D
{
private:
	SPMathLine2D m_hatchLine;

public:
	SPMathHatchLine2D();
	SPMathHatchLine2D(SPMathPoint2D point1, SPMathPoint2D point2);
	SPMathHatchLine2D(SPMathLine2D line);
	SPMathLine2D getHatchLine();
	void setHatchLine(SPMathLine2D hatchLine);
	vector<SPMathPoint2D> GetSortedListByX(vector<SPMathPoint2D> pointList);
	vector<SPMathPoint2D> GetIntersectionPoints(vector<SPMathLine2D> lineList);
	vector<SPMathHatchLine2D> GetHatchLine(vector<SPMathLine2D> lineList);
};

