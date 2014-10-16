#include <geometry/ChamberComponent.h>


void ChamberComponent::addChild(ChamberComponent* chamberComponent){
  m_children.emplace_back(chamberComponent);
}

ChamberComponent* ChamberComponent::getChild(unsigned iChild){
  if(m_children.size() > iChild){
    return m_children[iChild].get();
  }
  return nullptr;
}
