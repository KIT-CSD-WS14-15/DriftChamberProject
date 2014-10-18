#pragma once

class Cell;

#include <vector>
#include <iostream>


class ChamberComponent {
public:
  /** Virtual Constructor because ...*/
  virtual ~ChamberComponent() {}

  ChamberComponent(ChamberComponent* parent):
    m_children(), m_parent(parent)
  {}

  ChamberComponent* getChild(unsigned iChild);

  unsigned getNChild() {
    return m_children.size();
  }


  ChamberComponent* getParent() {
    return m_parent;
  }

  ChamberComponent* deepFirst()  {
    if (m_children.empty()) {
      return this;
    }
    return m_children[0]->deepFirst();
  }

  virtual unsigned getMaxY() const {
    unsigned sizeCounter = 0;
    for (auto & childPtr : m_children) {
      sizeCounter += childPtr->getMaxY();
    }
    return sizeCounter;
  }

  virtual std::string visualize() {
    for (auto & childPtr : m_children) {
      childPtr->visualize();
    }
    return "";
  }

  virtual unsigned getMyY() const;

  virtual unsigned getMaxX() const {
    m_parent->getMaxX();
  }

 Cell* getCellAt(unsigned xPosition, unsigned yPosition);

  virtual void fillCells() {

    for (auto & childPtr : m_children) {
      childPtr->fillCells();
    }
  }

protected:
  std::vector<ChamberComponent*> m_children;
  ChamberComponent* m_parent;

};
