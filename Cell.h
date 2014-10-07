#pragma once
#include <limits>
#include <string>

class Cell {
public:
	Cell(unsigned eDepositionCount = std::numeric_limits<unsigned>::max(),
		 unsigned driftTimeCount   = 0) :
			 m_eDepositionCount (eDepositionCount),
			 m_driftTimeCount   (driftTimeCount)
	{
	}

    std::string visualize(){
    	//see
    	//https://gist.github.com/ian128K/39a490e5aa8d3bb77a8b
    	//for color coding.
    	return "\x1B[97;40;1mO\x1B[0m";
    }


private:
  unsigned m_eDepositionCount;
  unsigned m_driftTimeCount;
};
