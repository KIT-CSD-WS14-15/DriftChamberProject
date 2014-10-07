#pragma once

#include <Cell.h>
#include <vector>
#include <memory>
#include <string>

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

	void addCell(std::shared_ptr<Cell> cell){
		m_cells.push_back(cell);
		m_dummyRow2.push_back(cell);
	}

private:
	std::vector< std::shared_ptr<Cell> > m_cells;
	std::vector< std::shared_ptr<Cell> > m_dummyRow2;

};
