#include "pch.h"
#include "SPMathLine2D.h"
#include <math.h>
#include "SPMathTolerance.h"
#include "SPMathVector2D.h"
#include "SPMathBox2D.h"
using namespace std;
// Implementation of line class 
SPMathLine2D::SPMathLine2D()
{

}

SPMathLine2D::SPMathLine2D(SPMathPoint2D startPoint, SPMathPoint2D endPoint)
{
	this->m_StartPoint = startPoint;
	this->m_EndPoint = endPoint;
}

//SPMathLine2D::SPMathLine2D(SPMathLine2D& objLineCopy)
//{
//	this->m_StartPoint = objLineCopy.m_StartPoint;
//	this->m_EndPoint = objLineCopy.m_EndPoint;
//}


SPMathPoint2D SPMathLine2D::GetStartPoint()
{
	return this->m_StartPoint;
}

SPMathPoint2D SPMathLine2D::GetEndPoint()
{
	return this->m_EndPoint;
}

void SPMathLine2D::SetStartPoint(SPMathPoint2D startPoint)
{
	this->m_StartPoint = startPoint;
}

void SPMathLine2D::SetEndPoint(SPMathPoint2D endPoint)
{
	this->m_EndPoint = endPoint;
}

bool SPMathLine2D::IsEqual(SPMathLine2D testLine)
{
	SPMathTolerance *tol = new SPMathTolerance();
	if (tol->IsPoint2Dequal(this->GetStartPoint(), testLine.GetStartPoint()) && tol->IsPoint2Dequal(this->GetEndPoint(), testLine.GetEndPoint()))
		return true;
	else
	{
		return false;
	}
}

bool SPMathLine2D::IsPointOnLine(SPMathPoint2D testPoint)
{
	double startPoint_and_testPointDist = this->GetStartPoint().Distance(testPoint);
	double endPoint_and_testPointDist = this->GetEndPoint().Distance(testPoint);
	double startPoint_and_endPointDist = this->GetStartPoint().Distance(this->GetEndPoint());
	if (startPoint_and_testPointDist + endPoint_and_testPointDist == startPoint_and_endPointDist)
		return true;
	else
	{
		return false;
	}
}

double SPMathLine2D::GetSlope()
{
	SPMathTolerance* tol = new SPMathTolerance();
	double slope;
	if (tol->IsEqual(this->GetEndPoint().GetXCoordinate(), this->GetStartPoint().GetXCoordinate()))
		if (tol->IsGreaterThan(this->GetEndPoint().GetYCoordinate(), this->GetStartPoint().GetYCoordinate()))
		{
			slope = PLUSINFINITY;
		}
		else
		{
			slope = MINUSINFINITY;
		}
	else
		slope = (this->GetEndPoint().GetYCoordinate() - this->GetStartPoint().GetYCoordinate()) / (this->GetEndPoint().GetXCoordinate() - this->GetStartPoint().GetXCoordinate());
	return slope;
}

bool SPMathLine2D::IsParallelTo(SPMathLine2D line)
{
	SPMathTolerance *tol = new SPMathTolerance();
	bool IsSuccess = false;
	if (tol)
	{
		if (tol->IsEqual(this->GetSlope(), line.GetSlope()) || tol->IsEqual(this->GetSlope(), -line.GetSlope()))
			IsSuccess = true;
		else
			IsSuccess = false;
	}
	return IsSuccess;
}

bool SPMathLine2D::IsTwoLinePerpendicular(SPMathLine2D line)
{
	double slopeProduct = 0;
	double slope1;
	double slope2;
	slope1 = this->GetSlope();
	slope2 = line.GetSlope();
	SPMathTolerance* tol = new SPMathTolerance();
	if(tol)
	{
		if (tol->IsEqual(slope1, PLUSINFINITY) || tol->IsEqual(slope1, MINUSINFINITY))
		{
			return(tol->IsZero(slope2));
		}
		else if(tol->IsEqual(slope2, PLUSINFINITY) || tol->IsEqual(slope2, MINUSINFINITY))
		{
			return(tol->IsZero(slope1));
		}
		else
		{
			slopeProduct = slope1 * slope2;
			return tol->IsEqual(slopeProduct, -1);
		}
	}
}

double SPMathLine2D::Orientation(SPMathPoint2D testPoint)
{
	double d1;
	SPMathVector2D v1(testPoint.GetXCoordinate() - m_StartPoint.GetXCoordinate(), testPoint.GetYCoordinate() - m_StartPoint.GetYCoordinate());
	SPMathVector2D v2(m_EndPoint.GetXCoordinate() - m_StartPoint.GetXCoordinate(), m_EndPoint.GetYCoordinate() - m_StartPoint.GetYCoordinate());
	d1 = v2.GetCrossProduct(v1);
	return d1;

}
double SPMathLine2D::Direction(SPMathPoint2D testPoint)
{
	double d1;
	SPMathVector2D v1(testPoint.GetXCoordinate() - m_StartPoint.GetXCoordinate(), testPoint.GetYCoordinate() - m_StartPoint.GetYCoordinate());
	SPMathVector2D v2(m_EndPoint.GetXCoordinate() - m_StartPoint.GetXCoordinate(), m_EndPoint.GetYCoordinate() - m_StartPoint.GetYCoordinate());
	d1 = v2.GetCrossProduct(v1);
	return d1;
}

bool SPMathLine2D::SegmentIntersect(SPMathLine2D line)
{
	SPMathBox2D box(line);

	SPMathBox2D box1(this->GetStartPoint(), this->GetEndPoint());

	if (box1.IsBoxIntersect(box) == false)
	{
		return false;
	}
	else
	{
		SPMathVector2D v1 = SPMathVector2D(line.GetStartPoint().GetXCoordinate(), line.GetStartPoint().GetYCoordinate());

		SPMathVector2D v2 = SPMathVector2D(line.GetEndPoint().GetXCoordinate(), line.GetEndPoint().GetYCoordinate());

		SPMathVector2D v3 = SPMathVector2D(this->GetStartPoint().GetXCoordinate(), this->GetStartPoint().GetYCoordinate());

		SPMathVector2D v4 = SPMathVector2D(this->GetEndPoint().GetXCoordinate(), this->GetEndPoint().GetYCoordinate());

		double d1, d2, d3, d4;

		d1 = this->Orientation(SPMathPoint2D(v1.GetVecXCoordinate(),v1.GetVecYCoorinate()));
		d2 = this->Orientation(SPMathPoint2D(v2.GetVecXCoordinate(), v2.GetVecYCoorinate()));

		d3 = line.Orientation(SPMathPoint2D(v3.GetVecXCoordinate(), v3.GetVecYCoorinate()));
		d4 = line.Orientation(SPMathPoint2D(v4.GetVecXCoordinate(), v4.GetVecYCoorinate()));

		if ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0) && (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))
			return true;

		else
		{
			if ((d1 == 0) && this->IsPointOnLine(SPMathPoint2D(v1.GetVecXCoordinate(), v1.GetVecYCoorinate())))
				return true;
			if ((d2 == 0) && this->IsPointOnLine(SPMathPoint2D(v2.GetVecXCoordinate(), v2.GetVecYCoorinate())))
				return true;
			if ((d3 == 0) && line.IsPointOnLine(SPMathPoint2D(v3.GetVecXCoordinate(), v3.GetVecYCoorinate())))
				return true;
			if ((d4 == 0) && line.IsPointOnLine(SPMathPoint2D(v4.GetVecXCoordinate(), v4.GetVecYCoorinate())))
				return true;
		}
		return false;
	}
}

SPMathPoint2D* SPMathLine2D::IntersectionPoint(SPMathLine2D line)
{

	SPMathPoint2D* intersectionPoint = NULL;

	double slopeOne = this->GetSlope();
	double slopeTwo = line.GetSlope();

	SPMathTolerance *tolerance = new SPMathTolerance();

	if ((MINUSINFINITY == slopeOne || PLUSINFINITY == slopeOne) &&
		(MINUSINFINITY == slopeTwo || PLUSINFINITY == slopeTwo))
	{
		if (line.IsPointOnLine(this->GetStartPoint()))
		{
			intersectionPoint = new SPMathPoint2D(this->GetStartPoint());
		}
		else if (line.IsPointOnLine(this->GetEndPoint()))
		{
			intersectionPoint = new SPMathPoint2D(this->GetEndPoint());
		}
	}
	else if ((MINUSINFINITY == slopeOne || PLUSINFINITY == slopeOne) &&
		(tolerance->IsZero(slopeTwo)))
	{
		intersectionPoint = new SPMathPoint2D(this->GetStartPoint().GetXCoordinate(), line.GetStartPoint().GetYCoordinate());

	}
	else if ((MINUSINFINITY == slopeTwo || PLUSINFINITY == slopeTwo) &&
		(tolerance->IsZero(slopeOne)))
	{
		intersectionPoint = new SPMathPoint2D(line.GetStartPoint().GetXCoordinate(), this->GetStartPoint().GetYCoordinate());

	}

	else if ((tolerance->IsZero(slopeOne) && tolerance->IsZero(slopeTwo)) ||
		tolerance->IsEqual(slopeOne, slopeTwo) || tolerance->IsEqual(slopeOne, -slopeTwo))
	{
		if (line.IsPointOnLine(this->GetStartPoint()))
		{
			intersectionPoint = new SPMathPoint2D(this->GetStartPoint());
		}
		else if (line.IsPointOnLine(this->GetEndPoint()))
		{
			intersectionPoint = new SPMathPoint2D(this->GetEndPoint());
		}

		if (IsPointOnLine(line.GetStartPoint()))
		{
			intersectionPoint = new SPMathPoint2D(line.GetStartPoint());
		}
		else if (IsPointOnLine(line.GetEndPoint()))
		{
			intersectionPoint = new SPMathPoint2D(line.GetEndPoint());
		}
	}
	else
	{
		double const_ValueOne = this->GetStartPoint().GetYCoordinate() - (slopeOne * this->GetStartPoint().GetXCoordinate());
		double const_ValueTwo = line.GetStartPoint().GetYCoordinate() - (slopeTwo * line.GetStartPoint().GetXCoordinate());



		if ((MINUSINFINITY == slopeOne || PLUSINFINITY == slopeOne) &&
			(!tolerance->IsZero(slopeTwo)))
		{
			double Y = slopeTwo * this->GetStartPoint().GetXCoordinate() + const_ValueTwo;
			intersectionPoint = new SPMathPoint2D(this->GetStartPoint().GetXCoordinate(), Y);

		}
		else if ((MINUSINFINITY == slopeTwo || PLUSINFINITY == slopeTwo) &&
			(!tolerance->IsZero(slopeOne)))
		{
			double Y = slopeOne * line.GetStartPoint().GetXCoordinate() + const_ValueOne;
			intersectionPoint = new SPMathPoint2D(line.GetStartPoint().GetXCoordinate(), Y);

		}
		else
		{
			double pointOne = (const_ValueOne - const_ValueTwo) / (slopeTwo - slopeOne);
			double pointTwo = slopeOne * pointOne + const_ValueOne;
			intersectionPoint = new SPMathPoint2D(pointOne, pointTwo);
		}
	}

	if (intersectionPoint != NULL && (!line.IsPointOnLine(SPMathPoint2D(intersectionPoint->GetXCoordinate(), intersectionPoint->GetYCoordinate())) || !this->IsPointOnLine(SPMathPoint2D(intersectionPoint->GetXCoordinate(), intersectionPoint->GetYCoordinate()))))
	{
		intersectionPoint = NULL;
	}

	return intersectionPoint;
}

