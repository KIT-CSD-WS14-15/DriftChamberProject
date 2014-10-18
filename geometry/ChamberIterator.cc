#include <geometry/ChamberIterator.h>

#include <iostream>

using namespace std;

ChamberIterator& ChamberIterator::operator ++()
{
  m_cell->getNextCell();
  return *this;
}

Cell* ChamberIterator::current()
{
  if (!m_cell) {
    cout << "m_cell is a NullPtr;" << endl;
  } else {
    cout << "m_cell is NOT a NullPtr;" << endl;
    cout << m_cell->getMaxX() << endl;
    cout << "m_cell is NOT a NullPtr;" << endl;
  }
  return m_cell;
}
