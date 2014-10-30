#pragma once
#include <core/Module.h>
#include <iostream>
#include <geometry/CompositeChamber.h>
#include <geometry/ColourStrategy.h>
#include <geometry/WidthStrategy.h>
#include <core/DataStore.h>
#include <vector>
#include <memory>

class CompositeGeometryCreatorModule : public Module {
  void begin() override {
    std::cout << "Creating a composite geometry!" << std::endl;
    // Config info:
    unsigned xSize = 100;
    std::vector<unsigned> nLayers = {8, 6, 6, 6, 6};

    std::shared_ptr<CompositeChamber> compositeChamberPtr(new CompositeChamber(xSize));
    CompositeChamber& compositeChamber = *(compositeChamberPtr.get());
    for (int ii = 0; ii < nLayers.size(); ii++) {
      SuperLayer* superLayer = 0;
      if (ii % 2) {
        superLayer = compositeChamber.addSuperLayer(new ColourStrategyBlue());
      } else {
        superLayer = compositeChamber.addSuperLayer(new ColourStrategyRed());
      }

      for (int jj = 0; jj < nLayers[ii]; ++jj) {
        if (jj < nLayers[ii] / 2) {
          superLayer->addLayer(new WidthStrategyOne());
        } else {
          superLayer->addLayer(new WidthStrategyTwo());
        }
      }
    }
    compositeChamber.fillCells();

    std::cout << "Maximum X of the Chamber: " << compositeChamber.getMaxX() << std::endl;
    std::cout << "Maximum Y of the Chamber: " << compositeChamber.getMaxY() << std::endl;

    compositeChamber.visualize();

    DataStore<CompositeChamber>::Instance().store("Chamber", std::shared_ptr<CompositeChamber>(compositeChamberPtr));
  }

  void event() override {
    (DataStore<CompositeChamber>::Instance().getStorable("Chamber"))->cleanUp();
  }
};
