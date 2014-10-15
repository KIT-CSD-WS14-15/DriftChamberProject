#include <geometry/ChamberIterator.h>

#include <geometry/Chamber.h>

#include <iostream>

using namespace std;

ChamberIterator& ChamberIterator::operator ++()
{
  if (m_xPosition < (m_chamber->getMaxX())) {
    m_xPosition++;
  }

  if (m_xPosition == m_chamber->getMaxX()) {
    m_yPosition++;
    m_xPosition = 0;
  }

  return *this;
}

shared_ptr<Cell> ChamberIterator::current()
{
  return m_chamber->getCellAt(m_xPosition, m_yPosition);
}
