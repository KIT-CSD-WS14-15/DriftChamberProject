#include <geometry/CompositeChamber.h>



std::shared_ptr<Cell> CompositeChamber::getCellAt(unsigned xPosition, unsigned yPosition) const
{/*
  if (yPosition < m_cells.size() && xPosition < m_cells[0].size()) {
    return m_cells[yPosition][xPosition];
  }
  */
  return nullptr;
}
