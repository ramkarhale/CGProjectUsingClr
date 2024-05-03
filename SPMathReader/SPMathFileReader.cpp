#include "pch.h"
#include "SPMathFileReader.h"
#include <string>
#include<iostream>
#include<iostream>
#include<fstream>
#include <sstream>
#include<list>

SPMathFileReader::SPMathFileReader()
{
	
}

SPMathFileReader::SPMathFileReader(std::list<SPMathLine2D> lines)
{
	this->m_readerlinelist = lines;
	/*for (size_t i = 0; i < this->m_readerlinelist.max_size(); i++)
	{
		this->m_readerlinelist[i] = lines[i];
	}*/
}

std::list<SPMathLine2D> SPMathFileReader::GetReaderLineList()
{
	return this->m_readerlinelist;
}

void SPMathFileReader::SetReaderLineList(std::list<SPMathLine2D> m_readerlinelist)
{
	this->m_readerlinelist = m_readerlinelist;
}
//std::list<SPMathLine2D> SPMathFileReader::ReadDataFromTextFile()
//{
//	std::list<SPMathLine2D> lineList;
//	std::string line;
//	std::ifstream myfile("C:/Users/DELL/source/repos/CGProjectUsingClr/rectangle_data.txt");
//
//	if (myfile.is_open())
//	{
//		//MessageBox::Show(Readfile);
//		while (!myfile.eof())
//		{
//
//			std::getline(myfile, line);
//			std::stringstream ss(line);
//			double pointarray[4] = {};           // array of points
//			int cnt = 0;
//			SPMathPoint2D startPoint;
//			SPMathPoint2D endPoint;
//
//
//			// Use while loop to check the getline() function condition.  
//			while (std::getline(ss, line, ','))
//			{
//				/*x = stoi( line);*/
//				pointarray[cnt] = stod(line);
//				cnt++;
//			}
//			startPoint.SetXCoordinate(pointarray[0]);
//			startPoint.SetYCoordinate(pointarray[1]);
//			endPoint.SetXCoordinate(pointarray[2]);
//			endPoint.SetYCoordinate(pointarray[3]);
//
//			SPMathLine2D line(startPoint, endPoint);
//			lineList.push_back(line);
//		}
//	}
//	return lineList;
//}
//
