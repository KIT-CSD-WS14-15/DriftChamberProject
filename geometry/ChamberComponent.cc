#include <geometry/ChamberComponent.h>
#include <geometry/Cell.h>

using namespace std;
ChamberComponent* ChamberComponent::getChild(unsigned iChild)
{
  if (m_children.size() > iChild) {
    return m_children.at(iChild);
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

Cell*  ChamberComponent::getCellAt(unsigned xPosition, unsigned yPosition) {
  if(xPosition < getMaxX()){
    std::cout << "I'm verbose" << xPosition << ", "<< yPosition << endl;
    if (yPosition >= getMyY() && yPosition <= getMyY() + getMaxY()){
      std::cout << "Hot candidate."  << endl;
      //Y Position is in the compound.
      if(m_children.empty()) {
        //try if we have a cell
        return dynamic_cast<Cell*> (this);
      }
      for (auto& childPtr : m_children){
        ChamberComponent* tmp = childPtr->getCellAt(xPosition, yPosition);
      }
    }
  }
  return nullptr;
}
