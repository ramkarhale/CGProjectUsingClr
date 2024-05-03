#include "pch.h"
#include "SPMathHatchLine2D.h"
#include "SPMathTolerance.h"

SPMathHatchLine2D::SPMathHatchLine2D()
{

}

SPMathHatchLine2D::SPMathHatchLine2D(SPMathPoint2D point1, SPMathPoint2D point2)
{
    SPMathTolerance *tolerance = new SPMathTolerance();
    if (tolerance)
    {
        if (tolerance->IsLessThan(point1.GetXCoordinate(), point2.GetXCoordinate()))
        {
            this->m_hatchLine = SPMathLine2D(point1, point2);
        }
        else
        {
            this->m_hatchLine = SPMathLine2D(point2, point1);
        }
    }
}

SPMathHatchLine2D::SPMathHatchLine2D(SPMathLine2D line)
{
    SPMathTolerance *tolerance = new SPMathTolerance();
    if (tolerance)
    {
        if (tolerance->IsLessThan(line.GetStartPoint().GetXCoordinate(), line.GetEndPoint().GetXCoordinate()))
        {
            this->m_hatchLine = line;
        }
        else
        {
            this->m_hatchLine = SPMathLine2D(line.GetEndPoint(), line.GetStartPoint());
        }
    }
}

SPMathLine2D SPMathHatchLine2D::getHatchLine()
{
	return this->m_hatchLine;
}

void SPMathHatchLine2D::setHatchLine(SPMathLine2D hatchLine)
{
	this->m_hatchLine = hatchLine;
}

vector<SPMathPoint2D> SPMathHatchLine2D::GetSortedListByX(vector<SPMathPoint2D> pointList)
{
    int i, j;

    SPMathTolerance *tolerance = new SPMathTolerance();

    SPMathPoint2D point;

    for (i = 0; i < pointList.size() - 1; i++)
        for (j = 0; j < pointList.size() - i - 1; j++)
            if (tolerance->IsGreaterThan(pointList[j].GetXCoordinate(), pointList[j + 1].GetXCoordinate()))
            {
                point = pointList[j];
                pointList[j] = pointList[j + 1];
                pointList[j + 1] = point;
            }
    return pointList;
}

vector<SPMathPoint2D> SPMathHatchLine2D::GetIntersectionPoints(vector<SPMathLine2D> lineList)
{
    vector<SPMathPoint2D> intersectionPointsList ;
    for(int i=0; i<lineList.size();i++)
    {
        SPMathPoint2D *point = lineList[i].IntersectionPoint(this->m_hatchLine);
        if (point != NULL)
        {
            intersectionPointsList.push_back(SPMathPoint2D(point->GetXCoordinate(),point->GetYCoordinate()));
        }

    }
    SPMathHatchLine2D hatchLine = this->m_hatchLine;
    intersectionPointsList = hatchLine.GetSortedListByX(intersectionPointsList);

    return intersectionPointsList;
}

vector<SPMathHatchLine2D> SPMathHatchLine2D::GetHatchLine(vector<SPMathLine2D> lineList)
{
    vector<SPMathHatchLine2D> hatchLineList ;
    SPMathHatchLine2D bigHatchLine = this->m_hatchLine;
    int i;
    int flag = 0;

    vector<SPMathPoint2D> intersectionPoints = bigHatchLine.GetIntersectionPoints(lineList);
    SPMathTolerance *tolerance = new SPMathTolerance();
    if (intersectionPoints.size() > 0)
    {
        if (intersectionPoints.size() == 2)
        {
            SPMathHatchLine2D hatchLine(intersectionPoints[0], intersectionPoints[1]);
            hatchLineList.push_back(hatchLine);
            return hatchLineList;
        }


        for (i = 0; i < intersectionPoints.size() - 1; i++)
        {
            if (!tolerance->IsPoint2Dequal(intersectionPoints[i], intersectionPoints[i + 1]))
            {
                if (i % 2 == 0)
                {
                    SPMathHatchLine2D hatchLine(SPMathLine2D(intersectionPoints[i], intersectionPoints[i + 1]));
                    //SPMathLine2D line = new SPMathLine2D(hatchLine);

                    if (flag == 0)
                    {
                        /* SPMathHatchLine2D hatch_Line = new SPMathHatchLine2D(line);
                         hatchLineList.Add(hatch_Line);*/
                        SPMathHatchLine2D hatch_Line(hatchLine);
                        hatchLineList.push_back(hatch_Line);
                    }
                }
            }
        }

    }
    return hatchLineList;
}

