#include "pch.h"
#include "SPMathPolygon2D.h"
#include "SPMathTolerance.h"
#include "SPMathBox2D.h"
using namespace std;
// Implementation

//SPMathPolygon2D::SPMathPolygon2D()
//{
//
//}
//
//SPMathPolygon2D::SPMathPolygon2D(list<SPMathLine2D> _polyLines)
//{
//
//	list<SPMathLine2D>::iterator it;
//	for (it = _polyLines.begin(); it != _polyLines.end(); it++)
//	{
//		SPMathLine2D line;
//		line = *it;
//		this->m_polyLines.push_back(line);
//	}
//
//}
//
//list<SPMathLine2D> SPMathPolygon2D::GetPolyLineList()
//{
//	return this->m_polyLines;
//}
//
//void SPMathPolygon2D::SetPolyLineList(list<SPMathLine2D> _polyLines)
//{
//	std::list<SPMathLine2D>::iterator it;
//	for (it = _polyLines.begin(); it != _polyLines.end(); it++)
//	{
//		SPMathLine2D line;
//		line = *it;
//		this->m_polyLines.push_back(line);
//	}
//}

SPMathPolygon2D::SPMathPolygon2D()
{

}

SPMathPolygon2D::SPMathPolygon2D(vector<SPMathLine2D> _polyLines)
{
	m_polyLines = vector<SPMathLine2D>();

	for(int i = 0;i <_polyLines.size(); i++)
	{
		SPMathLine2D line(_polyLines[i].GetStartPoint(), _polyLines[i].GetEndPoint());
		m_polyLines.push_back(line);
	}
}

vector<SPMathLine2D> SPMathPolygon2D::GetPolyLineList()
{
	return this->m_polyLines;
}

void SPMathPolygon2D::SetPolyLineList(vector<SPMathLine2D> _polyLines)
{
	m_polyLines = vector<SPMathLine2D>();
	for (int i = 0; i < _polyLines.size(); i++)
	{
		SPMathLine2D line(_polyLines[i].GetStartPoint(), _polyLines[i].GetEndPoint());
		m_polyLines.push_back(line);
	}
}

bool SPMathPolygon2D::IsClosed()
{
	SPMathTolerance *tol = new SPMathTolerance();
	if ( tol->IsPoint2Dequal( this->m_polyLines[0].GetStartPoint(),(this->m_polyLines[m_polyLines.size() - 1].GetEndPoint())))
	{
		return true;
	}
	else
		return false;
}

bool SPMathPolygon2D::IsSequenced()
{
	SPMathTolerance* tol = new SPMathTolerance();
	for (int i = 0; i < this->m_polyLines.size()-1; i++)
	{
		if (!(tol->IsPoint2Dequal(this->m_polyLines[i].GetEndPoint(), this->m_polyLines[i + 1].GetStartPoint())))
			return false;
		else
		{
			return true;
		}
	}
}

bool SPMathPolygon2D::GetSequenced()
{
	return false;
}

bool SPMathPolygon2D::IsSelfIntersect()
{
	SPMathTolerance* tol = new SPMathTolerance();
	for (int i = 0; i < this->m_polyLines.size(); i++)
	{
		for (int j = i + 1; j < this->m_polyLines.size(); j++)
		{
			if ((SPMathBox2D(this->m_polyLines[i]).IsBoxIntersect(SPMathBox2D(this->m_polyLines[i])) == true))
			{
				SPMathPoint2D *intersectionPoint = this->m_polyLines[i].IntersectionPoint(this->m_polyLines[j]);
				if (intersectionPoint == NULL)
				{
					continue;
				}
				SPMathPoint2D intersetionPointfromptr(intersectionPoint->GetXCoordinate(), intersectionPoint->GetYCoordinate());
				if ((tol->IsPoint2Dequal(intersetionPointfromptr,this->m_polyLines[i].GetEndPoint())) || tol->IsPoint2Dequal(intersetionPointfromptr,this->m_polyLines[i].GetStartPoint()) &&
					(tol->IsPoint2Dequal(intersetionPointfromptr, this->m_polyLines[j].GetEndPoint())) || tol->IsPoint2Dequal(intersetionPointfromptr, this->m_polyLines[j].GetStartPoint()))
				{
					continue;
				}
				else
				{
					return true;
				}
			}
		}
	}
	return false;
}

