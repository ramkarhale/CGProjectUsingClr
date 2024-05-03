#include "pch.h"
#include "SPMathPoint2D.h"
#include <math.h>
// Definition  
SPMathPoint2D::SPMathPoint2D()
{
	this->m_xCoordinate = 0.0;
	this->m_ycoordinate = 0.0;
}

SPMathPoint2D::SPMathPoint2D(double x_coordinate,double y_coordinate)
{
	if (x_coordinate == NULL && y_coordinate ==NULL)
	{
		throw 505;
	}
	this->m_xCoordinate = x_coordinate;
	this->m_ycoordinate = y_coordinate;
}

//SPMathPoint2D::SPMathPoint2D(SPMathPoint2D& objPoint)
//{
//	this->m_xCoordinate = objPoint.m_xCoordinate;
//	this->m_ycoordinate = objPoint.m_ycoordinate;
//}

double SPMathPoint2D::GetXCoordinate()
{
	return m_xCoordinate;
}

double SPMathPoint2D::GetYCoordinate()
{
	return m_ycoordinate;
}

void SPMathPoint2D::SetXCoordinate(double xcoordinate)
{
	this->m_xCoordinate = xcoordinate;
}

void SPMathPoint2D::SetYCoordinate(double ycoordinate)
{
	this->m_ycoordinate = ycoordinate;
}

double SPMathPoint2D::Distance(SPMathPoint2D objpoint)
{
	double dist = sqrt((objpoint.GetYCoordinate() - this->GetYCoordinate()) * (objpoint.GetYCoordinate() - this->GetYCoordinate()) +
		(objpoint.GetXCoordinate() - this->GetXCoordinate()) * (objpoint.GetXCoordinate() - this->GetXCoordinate()));
	return dist;
}


