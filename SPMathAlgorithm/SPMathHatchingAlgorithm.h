#pragma once
#include<vector>
#include "../SPMathLibrary/SPMathHatch2D.h"
class SPMathAlgorithm
{
private:
    double delta = 2;
    double _minX;
    double _maxX;

    double GetMinX();
    double GetMaxX();
public:
    vector<SPMathHatch2D> Algorithm(vector<SPMathLine2D> lineList);
    double GetMinFromVector(vector<double> darr);
    double GetMaxFromVector(vector<double> darr);
};

