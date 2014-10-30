#pragma once
#include <geometry/ChamberComponent.h>
#include <geometry/Layer.h>
#include <geometry/ColourStrategy.h>
#include <geometry/WidthStrategy.h>
#include <memory>

class SuperLayer : public ChamberComponent {
public:
  SuperLayer(ChamberComponent* parent, ColourStrategy const* colourStrategy = new ColourStrategyBlue()) :
    ChamberComponent(parent),
    m_colourStrategy(colourStrategy)

  {
  }

  Layer*  addLayer(const WidthStrategy* widthStrategy = new WidthStrategyOne()) {
    m_children.emplace_back(new Layer(this, m_colourStrategy, widthStrategy));
    return dynamic_cast<Layer*>(m_children.back());
  }
private:
  const ColourStrategy*   m_colourStrategy;
};
