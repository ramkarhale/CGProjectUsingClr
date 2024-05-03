// SPMathAlgorithm.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "SPMathHatchingAlgorithm.h"
#include<math.h>
#include "../SPMathLibrary/SPMathTolerance.h"

// TODO: This is an example of a library function
void fnSPMathAlgorithm()
{

}

double SPMathAlgorithm::GetMinX()
{
	return this->_minX;
}

double SPMathAlgorithm::GetMaxX()
{
	return this->_maxX;
}

vector<SPMathHatch2D> SPMathAlgorithm::Algorithm(vector<SPMathLine2D> lineList)
{

    vector<double> Xmin1;
    vector<double> Xmin2;

    for (int j = 0; j < lineList.size(); j++)
    {

        Xmin1.push_back(lineList[j].GetStartPoint().GetXCoordinate());
        Xmin2.push_back(lineList[j].GetEndPoint().GetXCoordinate());
    }

    _minX = min(GetMinFromVector(Xmin1) /*Xmin1.Min()*/, GetMinFromVector(Xmin2)/*Xmin2.Min()*/);
    _maxX = min(GetMaxFromVector(Xmin1)/*Xmin1.Max()*/, GetMaxFromVector(Xmin2)/*Xmin2.Max()*/);

    SPMathTolerance *tolerance = new SPMathTolerance();

    if (tolerance->IsGreaterThan(_minX, 2))
    {
        _minX = _minX - delta;
        _maxX = _maxX + delta;
    }

    vector<double> Ymin1 ;
    vector<double> Ymin2 ;

    for (int k = 0; k < lineList.size(); k++)
    {
        Ymin1.push_back(lineList[k].GetStartPoint().GetYCoordinate());
        Ymin2.push_back(lineList[k].GetEndPoint().GetYCoordinate());
    }


    double minY = min(GetMinFromVector(Ymin1)/*Ymin1.Min()*/, GetMinFromVector(Ymin2)/*Ymin2.Min()*/);
    double maxY = max(GetMaxFromVector(Ymin1)/*Ymin1.Max()*/, GetMaxFromVector(Ymin2)/*Ymin2.Max()*/);

    double i;

    vector<SPMathHatchLine2D> hatchLineList;

    for (i = minY + 1; i < maxY; i += 2)
    {
        SPMathLine2D line(SPMathPoint2D(_minX, i),SPMathPoint2D(_maxX, i));
        SPMathHatchLine2D hatchLine(line);
        hatchLineList.push_back(hatchLine);
    }

    SPMathHatch2D hatch(hatchLineList);
    vector<SPMathHatch2D> hatchList = hatch.DrawHatch(lineList);
    return hatchList;

}

double SPMathAlgorithm::GetMinFromVector(vector<double> darr)
{
    int i, j;
    double temp;
    SPMathTolerance* tolerance = new SPMathTolerance();

    for (i = 0; i < darr.size() - 1; i++)
        for (j = 0; j < darr.size() - i - 1; j++)
            if (tolerance->IsGreaterThan(darr[j], darr[j + 1]))
            {
                temp = darr[j];
                darr[j] = darr[j + 1];
                darr[j + 1] = temp;
            }
    return darr[0];
}

double SPMathAlgorithm::GetMaxFromVector(vector<double> darr)
{
    int i, j;
    double temp;
    SPMathTolerance* tolerance = new SPMathTolerance();

    for (i = 0; i < darr.size() - 1; i++)
        for (j = 0; j < darr.size() - i - 1; j++)
            if (tolerance->IsGreaterThan(darr[j], darr[j + 1]))
            {
                temp = darr[j];
                darr[j] = darr[j + 1];
                darr[j + 1] = temp;
            }
    return darr[darr.size() - 1];
}
