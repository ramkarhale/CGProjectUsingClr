#include "pch.h"
#include "SPMathVector2D.h"
#include <math.h>

SPMathVector2D::SPMathVector2D()
{
	this->m_vec_x_coord = 0;
	this->m_vec_y_coord = 0;
}

SPMathVector2D::SPMathVector2D(double x, double y)
{
	this->m_vec_x_coord = x;
	this->m_vec_y_coord = y;
}

void SPMathVector2D::CreateSPMathVector2DFromSPAndEP(SPMathPoint2D StartPoint, SPMathPoint2D EndPoint)
{
	this->m_vec_x_coord = EndPoint.GetXCoordinate() - StartPoint.GetXCoordinate();
	this->m_vec_y_coord = EndPoint.GetYCoordinate() - StartPoint.GetYCoordinate();
}

void SPMathVector2D::CreateSPMathVector2DFromLine(SPMathLine2D line)
{
	this->m_vec_x_coord = line.GetEndPoint().GetXCoordinate() - line.GetStartPoint().GetXCoordinate();
	this ->m_vec_y_coord = line.GetEndPoint().GetYCoordinate() - line.GetStartPoint().GetYCoordinate();
}

void SPMathVector2D::CreateSPMathVector2DFromPoint(SPMathPoint2D point)
{
	this->m_vec_x_coord = point.GetXCoordinate();
	this->m_vec_y_coord = point.GetYCoordinate();
}

double SPMathVector2D::GetVecXCoordinate()
{
	return this->m_vec_x_coord;
}

double SPMathVector2D::GetVecYCoorinate()
{
	return this->m_vec_y_coord;

}

double SPMathVector2D::GetCrossProduct(SPMathVector2D vector)   // cross product in two 2D for check directions
{
	double dCrossProduct;
	dCrossProduct = this->GetVecXCoordinate() * vector.GetVecYCoorinate() - this->GetVecYCoorinate() * vector.GetVecXCoordinate();
	return dCrossProduct;
}

double SPMathVector2D::GetDotProduct(SPMathVector2D vector)
{
	double dotProduct;
	dotProduct = this->GetVecXCoordinate() * vector.GetVecXCoordinate() + this->GetVecYCoorinate() * vector.GetVecYCoorinate();
	return dotProduct;
}

double SPMathVector2D::GetMagnitude()
{
	double magnitude = 0;
	magnitude = (this->m_vec_x_coord + this->m_vec_y_coord) / (sqrt((this->m_vec_x_coord * this->m_vec_x_coord) + (this->m_vec_y_coord * this->m_vec_y_coord)));
	return magnitude;
}

double SPMathVector2D::Distance(SPMathVector2D vector)
{
	double dist = sqrt((vector.GetVecYCoorinate() - this->GetVecYCoorinate()) * (vector.GetVecYCoorinate() - this->GetVecYCoorinate()) +
		(vector.GetVecXCoordinate() - this->GetVecXCoordinate()) * (vector.GetVecXCoordinate() - this->GetVecXCoordinate()));
	return dist;
}
