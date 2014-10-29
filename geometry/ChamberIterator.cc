#include <geometry/ChamberIterator.h>

#include <iostream>

using namespace std;

ChamberIterator& ChamberIterator::operator ++()
{
  m_cell = m_cell->getNextCell();
  return *this;
}

Cell* ChamberIterator::current()
{
  return m_cell;
}
