#pragma once

#include <geometry/SpecialCell.h>
#include <geometry/ChamberIterator.h>

#include <vector>
#include <memory>
#include <iostream>

/** The geometric representation of the drift chamber.
 */
class Chamber {
public:
  /** Constructor for a Chamber with a number of lines given by parameter. */
  Chamber(unsigned nLayers = 4);


  /** Prints some visualization on the command line.
   *
   *  This is one of the major functions of this programm,
   *  as the chamber "knows" as well about its energy depostion.
   */
  void visualize() const;

  ChamberIterator first() const;

  /** This is a very preliminary way of adding cells.
   *
   *  The reason is, that one big task for the project is to write
   *  a new representation for the Chamber.
   */
  void addCell();

  /** "Empties" all cells by resetting their energy deposition.
   *
   *  This function is used as well in the GeometryCreator.
   */
  void cleanUp();

  std::shared_ptr<Cell> getCellAt(unsigned xPosition, unsigned yPosition) const;

  unsigned getMaxX() const {
    return (m_cells[0].size());
  }

  unsigned getMaxY() const {
    return m_cells.size();
  }

private:
  std::vector< std::vector<std::shared_ptr<Cell> > > m_cells;
};
