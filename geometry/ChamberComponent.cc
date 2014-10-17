#include <geometry/ChamberComponent.h>

ChamberComponent* ChamberComponent::getChild(unsigned iChild)
{
  if (m_children.size() > iChild) {
    return m_children.at(iChild).get();
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

