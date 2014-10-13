#pragma once
#include <string>

class Cell {
public:
	/** Constructs an empty drift cell with given position as lower left corner. */
	Cell(unsigned xPosition, unsigned yPosition) :
		     m_xPosition (xPosition), m_yPosition (yPosition),
			 m_eDepositionCount (0)
	{}

	/** Sets the energy deposition of a cell to 0. */
	void resetEDeposition (){
		m_eDepositionCount = 0;
	}

	/** Adds a given amount of energy to the cell. */
	void addEDeposition(unsigned eDepositionCount){
		m_eDepositionCount += eDepositionCount;
	}

	/** A string to be printed in context.
	 *
	 *  In this case a black background with an O for an empty cell
	 *  and an X for a hit cell is printed.
	 */
    std::string visualize(){
    	//see
    	//https://gist.github.com/ian128K/39a490e5aa8d3bb77a8b
    	//for color coding.
    	if (m_eDepositionCount ==0 ){
    	  return "\x1B[97;40;1mO\x1B[0m";
    	} else {
    	  return "\x1B[97;40;1mX\x1B[0m";
    	}
    }


private:
  unsigned m_xPosition;
  unsigned m_yPosition;

  unsigned m_eDepositionCount;
};
