#pragma once
#include<list>
#include "../SPMathLibrary/SPMathLine2D.h"
class SPMathFileReader
{
private:
	std::list<SPMathLine2D> m_readerlinelist;

public:
	SPMathFileReader();
	SPMathFileReader(std::list<SPMathLine2D> lines);

	std::list<SPMathLine2D> GetReaderLineList();
	void SetReaderLineList(std::list<SPMathLine2D> m_readerlinelist);
	/*std::list<SPMathLine2D> ReadDataFromTextFile();*/

};

