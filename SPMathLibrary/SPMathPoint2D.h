#pragma once
class SPMathPoint2D
{
private:
		// Member variables 
		double m_xCoordinate;
		double m_ycoordinate;
public:
		// Constructor,s and destructor
		SPMathPoint2D();
		SPMathPoint2D(double x, double y);
		//SPMathPoint2D(SPMathPoint2D& objPoint);

		// get set methods 
		double GetXCoordinate();
		double GetYCoordinate();

		void  SetXCoordinate(double xcoordinate);
		void  SetYCoordinate(double ycoordinate);

		// operator overloading 



		//Method's or functions
		double Distance(SPMathPoint2D objpoint);
		


};

