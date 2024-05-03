#pragma once
#include "SPMathLine2D.h"
#include<list>
#include<vector>
using namespace std;

class SPMathPolygon2D
{
private:
	vector<SPMathLine2D> m_polyLines;

public:
	SPMathPolygon2D();
	SPMathPolygon2D(vector<SPMathLine2D> _polyLines);

	// get set methods
	vector<SPMathLine2D> GetPolyLineList();
	void SetPolyLineList(vector<SPMathLine2D> _polyLines);
	bool IsClosed();
	bool IsSequenced();
	bool GetSequenced();
	bool IsSelfIntersect();

	// methods or functions 

};

