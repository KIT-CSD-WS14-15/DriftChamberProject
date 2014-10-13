#pragma once

#include <Cell.h>

#include <vector>
#include <memory>
#include <iostream>

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
		for (auto& cellPtr : m_dummyRow4){
			std::cout << cellPtr->visualize();
		}
		std::cout << std::endl;

		for (auto& cellPtr : m_dummyRow3){
			std::cout << cellPtr->visualize();
		}
		std::cout << std::endl;

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
		m_dummyRow3.push_back(std::shared_ptr<Cell>(new Cell(m_cells.size(), 3)));
		m_dummyRow4.push_back(std::shared_ptr<Cell>(new Cell(m_cells.size(), 4)));
	}

	/** "Empties" all cells by resetting their energy deposition.
	 *
	 *  This function is used as well in the GeometryCreator.
	 */
	void cleanUp(){
		for (auto& cellPtr : m_cells){
			cellPtr->resetEDeposition();
		}

		for (auto& cellPtr : m_dummyRow2){
			cellPtr->resetEDeposition();
		}

		for (auto& cellPtr : m_dummyRow3){
			cellPtr->resetEDeposition();
		}

		for (auto& cellPtr : m_dummyRow4){
			cellPtr->resetEDeposition();
		}
	}

	std::shared_ptr<Cell> getCellAt(unsigned xPosition, unsigned yPosition){
      if (xPosition < m_cells.size()){
        if (yPosition == 0) {
        	return m_cells[xPosition];
        } else if (yPosition == 1) {
        	return m_dummyRow2[xPosition];
        } else if (yPosition == 2){
        	return m_dummyRow3[xPosition];
        } else if (yPosition == 3){
        	return m_dummyRow4[xPosition];
        } else {
        	return nullptr;
        }
      } else {
    	  return nullptr;
      }
	}

	unsigned getMaxX(){
		return (m_cells.size() + 1);
	}

	unsigned getMaxY(){
		return 4;
	}

private:
	std::vector< std::shared_ptr<Cell> > m_cells;
	std::vector< std::shared_ptr<Cell> > m_dummyRow2;
	std::vector< std::shared_ptr<Cell> > m_dummyRow3;
	std::vector< std::shared_ptr<Cell> > m_dummyRow4;

};
