#pragma once

#include <geometry/ChamberComponent.h>

#include <string>


class Cell : public ChamberComponent {
public:
  /** Virtual destructor, as this is now a base class. */
  virtual ~Cell() {};

  /** Constructs an empty drift cell with given position as lower left corner. */
  Cell(unsigned xPosition, unsigned yPosition, ChamberComponent* parent = nullptr) :
    ChamberComponent(parent),
    m_xPosition(xPosition), m_yPosition(yPosition),
    m_eDepositionCount(0)
  {}

  /** Returns the central position of the cell. */
  float getXPosition() const {
    return m_xPosition + 0.5;
  }

  /** Returns the central position of the cell. */
  float getYPosition() const {
    return m_yPosition + 0.5;
  }

  /** Sets the energy deposition of a cell to 0. */
  void resetEDeposition() {
    m_eDepositionCount = 0;
  }

  /** Adds a given amount of energy to the cell. */
  void addEDeposition(unsigned eDepositionCount) {
    m_eDepositionCount += eDepositionCount;
  }

  /** Returns a counter of the energy deposition. */
  unsigned getEDeposition() {
    return m_eDepositionCount;
  }

  /** A string to be printed in context.
   *
   *  In this case a black background with an O for an empty cell
   *  and an X for a hit cell is printed.
   */
  virtual std::string visualize() {
    //see
    //https://gist.github.com/ian128K/39a490e5aa8d3bb77a8b
    //for color coding.
    if (m_eDepositionCount == 0) {
      return "\x1B[97;40;1mO\x1B[0m";
    } else {
      return "\x1B[97;40;1mX\x1B[0m";
    }
  }


protected:
  unsigned m_xPosition;
  unsigned m_yPosition;

  unsigned m_eDepositionCount;
};
