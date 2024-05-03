#include "pch.h"
#include "SPMathHatch2D.h"

SPMathHatch2D::SPMathHatch2D()
{

}

SPMathHatch2D::SPMathHatch2D(vector<SPMathHatchLine2D> hatchLineList)
{
    this->_hatchLineList = hatchLineList;
}

vector<SPMathHatchLine2D> SPMathHatch2D::GetHatch()
{
    return this->_hatchLineList;
}

vector<SPMathHatch2D> SPMathHatch2D::DrawHatch(vector<SPMathLine2D> linelist)
{
    SPMathHatch2D hatch(this->_hatchLineList);
    vector<SPMathHatchLine2D> hatchLineList;

    vector<SPMathHatch2D> hatchList;

    for(int i=0; i< hatch._hatchLineList.size();i++)
    {
        hatchLineList = hatch._hatchLineList[i].GetHatchLine(linelist);

        SPMathHatch2D tempHatch(hatchLineList);
        hatchList.push_back(tempHatch);
    }

    return hatchList;
}
