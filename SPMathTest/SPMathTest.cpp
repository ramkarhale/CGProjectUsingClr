// SPMathTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../SPMathLibrary/SPMathPoint2D.h"
#include "../SPMathLibrary/SPMathLine2D.h"
#include "../SPMathLibrary/SPMathTolerance.h"
#include "../SPMathLibrary/SPMathBox2D.h"
#include "../SPMathLibrary/SPMathPolygon2D.h"
#include "../SPMathLibrary/SPMathHatchLine2D.h"
#include "../SPMathAlgorithm/SPMathHatchingAlgorithm.h"
using namespace std;


void TestSPMathPoint2D();
void TestSPMathTolerance();
void TestBox();
void TestLineFunctions();
void PolygonTest();
void HatchLineTest();
void HatchingAlgorithmTest();


int main()
{

    //TestSPMathPoint2D();
    //TestSPMathTolerance();
    //TestBox();
    //TestLineFunctions();
    //PolygonTest();
    //HatchLineTest();
    HatchingAlgorithmTest();
    

}

void TestSPMathPoint2D()  // Test Line functions 
{
    try
    {
        double x = NULL;;
        double y = NULL;;
        SPMathPoint2D sppoint1(10, 10);
        SPMathPoint2D sppoint2(40, 40);
        SPMathPoint2D sppoint3(10, 12);
        //SPMathPoint2D sppoint4(x,y);
        SPMathLine2D testLine(sppoint1, sppoint2);

        bool IsTrue = false;

        IsTrue = testLine.IsPointOnLine(sppoint3);
        std::cout << "Is point on the line or not " << IsTrue;
    }
    catch (...)
    {
          cout << "Exception - point cannot be null.\n";
    }
   
}
void TestSPMathTolerance()
{
    try
    {
        SPMathTolerance* objTol = new SPMathTolerance();
        bool IsTrue = false;
        double x = 10;
        double y = 10.999999;

        IsTrue = objTol->IsEqual(x, y);
        std::cout << "Is two points are equal or not " << IsTrue;
    }
    catch (...)
    {
        cout << "Exception - double value cannnot be null.\n";
    }

    


}

void TestBox()
{
    SPMathBox2D* objBox = new SPMathBox2D();
    bool IsTrue = false;
    SPMathPoint2D sppoint1(10, 10);
    SPMathPoint2D sppoint2(20, 20);
    SPMathPoint2D sppoint3(30, 10);
    SPMathPoint2D sppoint4(40, 20);
    //SPMathPoint2D sppoint4(x,y);
    SPMathLine2D testLine1(sppoint1, sppoint2);
    SPMathLine2D testLine2(sppoint3, sppoint4);
    if (objBox)
    {
        IsTrue = objBox->IsTwoBoxIntersect(testLine1, testLine2);
        std::cout << "Is two boxes are intersect " << IsTrue;
    }
        
}

void TestLineFunctions()
{
    SPMathPoint2D *intersectionPoint = NULL;
    bool IsSuccess = false;
    SPMathPoint2D sp1(10, 10);
    SPMathPoint2D ep1(20, 10);
    SPMathPoint2D sp2(10, 15);
    SPMathPoint2D ep2(10, 20);
    SPMathPoint2D testpoint(30, 10);
    SPMathLine2D line1 = SPMathLine2D(sp1, ep1);
    SPMathLine2D line2 = SPMathLine2D(sp2, ep2);

    intersectionPoint = line1.IntersectionPoint(line2);
    if(intersectionPoint)
        cout << "Intersection point is" << " x coord :" << intersectionPoint->GetXCoordinate() << " y coord :" << intersectionPoint->GetYCoordinate() << endl;

    /*IsSuccess = line1.SegmentIntersect(line2);
    cout << "segment intersect test  : " << IsSuccess << endl;*/

   /* double dotp = 0;
    dotp = line1.Orientation(testpoint);
    cout << "orientation of point with respect to line " << dotp << endl;*/
    
}

void PolygonTest()
{
    bool IsSuccess = false;
    vector<SPMathLine2D> veclinelist;
    SPMathLine2D line1(SPMathPoint2D(20, 10), SPMathPoint2D(30, 10));
    SPMathLine2D line2(SPMathPoint2D(30, 10), SPMathPoint2D(30, 20));
    SPMathLine2D line3(SPMathPoint2D(30, 20), SPMathPoint2D(20, 20));
    SPMathLine2D line4(SPMathPoint2D(20, 20), SPMathPoint2D(20, 10));
    veclinelist.push_back(line1);
    veclinelist.push_back(line2);
    veclinelist.push_back(line3);
    veclinelist.push_back(line4);

    SPMathPolygon2D polygon(veclinelist);

    IsSuccess = polygon.IsClosed();
    

    cout << "closed polygon test is " << IsSuccess << endl;
}

void HatchLineTest()
{
    vector<SPMathHatchLine2D> hatchlinelist;
    vector<SPMathPoint2D> pointList;
    SPMathLine2D line1(SPMathPoint2D(20, 20),SPMathPoint2D(40, 60));
    SPMathLine2D line2(SPMathPoint2D(40, 60),SPMathPoint2D(60, 20));
    SPMathLine2D line3(SPMathPoint2D(60, 20),SPMathPoint2D(80, 60));
    SPMathLine2D line4(SPMathPoint2D(80, 60),SPMathPoint2D(10, 20));

    vector<SPMathLine2D> lineList;
    lineList.push_back(line1);
    lineList.push_back(line2);
    lineList.push_back(line3);
    lineList.push_back(line4);

    SPMathHatchLine2D hatchLine(SPMathPoint2D(0,40),SPMathPoint2D(80,40));
    hatchlinelist = hatchLine.GetHatchLine(lineList);

    pointList = hatchLine.GetIntersectionPoints(lineList);

}

void HatchingAlgorithmTest()
{

    SPMathAlgorithm halgo;
    double value1;
    double value2;
    vector<double> darr;
    darr.push_back(10);
    darr.push_back(12);
    darr.push_back(8);
    darr.push_back(5);
    value1 = halgo.GetMaxFromVector(darr);
    value2 = halgo.GetMinFromVector(darr);

    cout << "max value from vector : " << value1 << endl;
    cout << "min value from vector : " << value2 << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
