#pragma once

#include <Cell.h>
#include <vector>
#include <memory>

/** The geometric representation of the drift chamber.
 */
class Chamber {
public:
	/** Prints some visualization on the command line.
	 *
	 *  This is one of the major functions of this programm,
	 *  as the chamber "knows" as well about its energy depostion.
	 */
	void visualize() const {
		std::cout << "Print current Chamber" << std::endl;
		for (auto& cellPtr : m_dummyRow2){
			std::cout << cellPtr->visualize();
		}
		std::cout << std::endl;

		for (auto& cellPtr : m_cells){
			std::cout << cellPtr->visualize();
		}
		std::cout << std::endl;
	}

	/** This is a very preliminary way of adding cells.
	 *
	 *  The reason is, that one big task for the project is to write
	 *  a new representation for the Chamber.
	 */
	void addCell(){
		m_cells.push_back(    std::shared_ptr<Cell>(new Cell(m_cells.size(), 1)));
		m_dummyRow2.push_back(std::shared_ptr<Cell>(new Cell(m_cells.size(), 2)));
	}

	/** "Empties" all cells by resetting their energy deposition.
	 *
	 *  This function is used as well in the GeometryCreator.
	 */
	void cleanUp(){
		for (auto& cellPtr : m_cells){
			cellPtr->setEDeposition(0);
		}

		for (auto& cellPtr : m_dummyRow2){
			cellPtr->setEDeposition(0);
		}
	}

	std::shared_ptr<Cell> getCellAt(unsigned xPosition, unsigned yPosition){
      if (xPosition < m_cells.size()){
        if (yPosition == 0) {
        	return m_cells[xPosition];
        } else {
        	return m_dummyRow2[xPosition];
        }
      } else {
    	  return nullptr;
      }
	}

	unsigned getMaxX(){
		return (m_cells.size() + 1);
	}

	unsigned getMaxY(){
		return 2;
	}

private:
	std::vector< std::shared_ptr<Cell> > m_cells;
	std::vector< std::shared_ptr<Cell> > m_dummyRow2;

};
