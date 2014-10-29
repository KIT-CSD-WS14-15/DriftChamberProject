#include <geometry/ChamberComponent.h>
#include <geometry/Cell.h>
#include <iostream>


using namespace std;
ChamberComponent* ChamberComponent::getChild(unsigned iChild)
{
  if (m_children.size() > iChild) {
    return m_children.at(iChild);
  }
  return nullptr;
}

ChamberComponent* ChamberComponent::getNextChild(ChamberComponent* currentChild)
{
  for (auto childPtr = m_children.begin(); childPtr != m_children.end(); childPtr++) {
    if (*childPtr == currentChild) {
      childPtr++;
      if (childPtr != m_children.end()) {
        return *childPtr;
      } else {
        if (m_parent) {
          ChamberComponent* neighbour = m_parent->getNextChild(this);
          if (neighbour) {
            return neighbour->getChild(0);
          }
        }
      }
      return nullptr;
    }
  }
  return nullptr;
}


unsigned ChamberComponent::getMyY() const
{
  unsigned sizeCounter = 0;
  if (m_parent) {
    sizeCounter += m_parent->getMyY();

    for (int ii = 0; ii < m_parent->getNChild(); ++ii) {
      ChamberComponent* chamberComponent = m_parent->getChild(ii);
      if (chamberComponent == this) {
        break;
      }
      sizeCounter += chamberComponent->getMaxY();
    }
  }
  return sizeCounter;
}

Cell*  ChamberComponent::getCellAt(unsigned xPosition, unsigned yPosition)
{
  if (xPosition < getMaxX()) {

    if (yPosition >= getMyY() && yPosition <= getMyY() + getMaxY()) {
      //Y Position is in the compound.
      if (m_children.empty()) {
        //try if we have a cell
        Cell* cell = dynamic_cast<Cell*>(this);
        if (cell != 0) {
          if (cell->xIsInside(xPosition)) {
            return cell;
          }
        }
        return 0;
      }
      for (auto & childPtr : m_children) {
        Cell* tmp = childPtr->getCellAt(xPosition, yPosition);
        if (tmp) {
          return tmp;
        }
      }
    }
  }
  return nullptr;
}
