#pragma once

#include <geometry/Cell.h>

#include <memory>

/** An Iterator for a  CompositeChamber.
 *
 *  While the principle is similar, the actual implementation is a bit simplified
 *  compared with the "canonical" one described at:
 *
 *  http://de.wikipedia.org/wiki/Iterator_(Entwurfsmuster)
 */
class ChamberIterator {
public:

  /** This constructor comes always to live at the beginning of the cell.*/
  ChamberIterator(Cell* cell) :
    m_cell(cell)
  {}

  /** Prefix operator. */
  ChamberIterator& operator++();

  /** Returns the cell at which currently is pointed to.
   *
   *  If we are done with the transversal through the whole chamber,
   *  we get back a nullptr.
   */
  Cell* current();

private:
  Cell* m_cell;
};
