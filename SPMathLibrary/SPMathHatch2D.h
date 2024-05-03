#pragma once
#include "SPMathHatchLine2D.h"
#include<vector>
class SPMathHatch2D
{
	private:
		vector<SPMathHatchLine2D> _hatchLineList;
public:
	SPMathHatch2D();
	SPMathHatch2D(vector<SPMathHatchLine2D> hatchLineList);
	vector<SPMathHatchLine2D> GetHatch();
	vector<SPMathHatch2D> DrawHatch(vector<SPMathLine2D> linelist);
};

