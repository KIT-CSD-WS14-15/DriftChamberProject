#pragma once

#include <Cell.h>
#include <vector>
#include <memory>

class Chamber {
public:
	void visualize() const {
		std::cout << "Print current Chamber" << std::endl;
		for (auto& cellPtr : m_cells){
			std::cout << cellPtr->visualize();
		}
		std::cout << std::endl;

		for (auto& cellPtr : m_dummyRow2){
			std::cout << cellPtr->visualize();
		}
		std::cout << std::endl;
	}

	void addCell(){
		m_cells.push_back(    std::shared_ptr<Cell>(new Cell(m_cells.size(), 1)));
		m_dummyRow2.push_back(std::shared_ptr<Cell>(new Cell(m_cells.size(), 2)));
	}

	void cleanUp(){
		for (auto& cellPtr : m_cells){
			cellPtr->setEDeposition(0);
		}

		for (auto& cellPtr : m_dummyRow2){
			cellPtr->setEDeposition(0);
		}
	}

private:
	std::vector< std::shared_ptr<Cell> > m_cells;
	std::vector< std::shared_ptr<Cell> > m_dummyRow2;

};
