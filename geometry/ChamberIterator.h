#pragma once

//#include <geometry/Chamber.h>
class Chamber;
#include <geometry/Cell.h>

#include <memory>

/** An Iterator for a  Chamber.
 *
 *  While the principle is similar, the actual implementation is a bit simplified
 *  compared with the "canonical" one described at:
 *
 *  http://de.wikipedia.org/wiki/Iterator_(Entwurfsmuster)
 */
class ChamberIterator {
public:

  /** This constructor comes always to live at the beginning of the cell.*/
  ChamberIterator(Chamber const*   const chamber) :
    m_chamber(chamber), m_xPosition(0), m_yPosition(0)
  {}

  /** Prefix operator. */
  ChamberIterator& operator++();

  /** Returns the cell at which currently is pointed to.
   *
   *  If we are done with the transversal through the whole chamber,
   *  we get back a nullptr.
   */
  std::shared_ptr<Cell> current();

private:
  unsigned m_xPosition;
  unsigned m_yPosition;

  Chamber const* const m_chamber;
};
