#include <geometry/ChamberIterator.h>

#include <iostream>

using namespace std;

ChamberIterator& ChamberIterator::operator ++()
{
  m_cell->getNext();
  return *this;
}

shared_ptr<Cell> ChamberIterator::current()
{
  return shared_ptr<Cell> (m_cell);
}
