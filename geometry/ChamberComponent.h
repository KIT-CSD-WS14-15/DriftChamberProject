#pragma once

#include <vector>
#include <memory>

class ChamberComponent {
public:
  void addChild(ChamberComponent* chmaberComponent);
  ChamberComponent* getChild(unsigned iChild);
//  const ChamberCoponent& getChild() const;
private:
  std::vector<std::shared_ptr<ChamberComponent> > m_children;

};
