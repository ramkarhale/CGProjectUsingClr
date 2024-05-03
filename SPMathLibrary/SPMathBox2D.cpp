#include "pch.h"
#include "SPMathBox2D.h"
using namespace std;
#include<math.h>

SPMathBox2D::SPMathBox2D()
{

}

SPMathBox2D::SPMathBox2D(SPMathPoint2D point1, SPMathPoint2D point2)
{
	m_MinPoint = SPMathPoint2D(fmin(point1.GetXCoordinate(), point2.GetXCoordinate()), fmin(point1.GetYCoordinate(), point2.GetYCoordinate()));
	m_MaxPoint = SPMathPoint2D(fmax(point1.GetXCoordinate(),point2.GetXCoordinate()),fmax(point1.GetYCoordinate(),point2.GetYCoordinate()));
}

SPMathBox2D::SPMathBox2D(SPMathLine2D line)
{
	m_MinPoint = SPMathPoint2D(fmin(line.GetStartPoint().GetXCoordinate(), line.GetEndPoint().GetXCoordinate()), fmin(line.GetStartPoint().GetYCoordinate(), line.GetEndPoint().GetYCoordinate()));
	m_MaxPoint = SPMathPoint2D(fmax(line.GetStartPoint().GetXCoordinate(), line.GetEndPoint().GetXCoordinate()), fmax(line.GetStartPoint().GetYCoordinate(), line.GetEndPoint().GetYCoordinate()));
}
bool SPMathBox2D::IsTwoBoxIntersect(SPMathLine2D line1, SPMathLine2D line2)
{
	if (line1.GetEndPoint().GetXCoordinate() < line2.GetStartPoint().GetXCoordinate() || line1.GetEndPoint().GetYCoordinate() < line2.GetStartPoint().GetYCoordinate()
		|| (line2.GetEndPoint().GetXCoordinate() < line1.GetStartPoint().GetXCoordinate() || line2.GetEndPoint().GetYCoordinate() < line1.GetStartPoint().GetYCoordinate()))
		return false;
	else
		return true;

}
bool SPMathBox2D::IsBoxIntersect(SPMathBox2D box)
{
	if ((box.m_MinPoint.GetXCoordinate() > this->m_MaxPoint.GetXCoordinate()|| box.m_MinPoint.GetYCoordinate() > this->m_MaxPoint.GetYCoordinate()) || 
		(this->m_MinPoint.GetXCoordinate() > box.m_MaxPoint.GetXCoordinate() || this->m_MinPoint.GetYCoordinate()> box.m_MaxPoint.GetYCoordinate()))
	{
		return false;// not intersected 
	}
	else
	{
		return true;
	}
}
//
//SPMathBox2D::SPMathBox2D(list<SPMathLine2D> lineList)
//{
//	m_MinPoint;
//	/*m_MinPoint = SPMathPoint2D(fmin(point1.GetXCoordinate(), point2.GetXCoordinate()), fmin(point1.GetYCoordinate(), point2.GetYCoordinate()));
//	m_MaxPoint = SPMathPoint2D(fmax(point1.GetXCoordinate(), point2.GetXCoordinate()), fmax(point1.GetYCoordinate(), point2.GetYCoordinate()));*/
//}

