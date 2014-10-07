#pragma once
#include <string>

class Cell {
public:
	Cell(unsigned xPosition, unsigned yPosition) :
		     m_xPosition (xPosition), m_yPosition (yPosition),
			 m_eDepositionCount (0)
	{}

	void setEDeposition (unsigned eDepositionCount){
		m_eDepositionCount = eDepositionCount;
	}

    std::string visualize(){
    	//see
    	//https://gist.github.com/ian128K/39a490e5aa8d3bb77a8b
    	//for color coding.
    	return "\x1B[97;40;1mO\x1B[0m";
    }


private:
  unsigned m_xPosition;
  unsigned m_yPosition;

  unsigned m_eDepositionCount;
};
