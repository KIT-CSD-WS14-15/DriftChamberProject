#include <geometry/Cell.h>
#include <geometry/Layer.h>
#include <geometry/SuperLayer.h>
#include <geometry/CompositeChamber.h>

#include "gtest/gtest.h"

TEST(CompositeChamberTest, chamberConstruction)
{
  CompositeChamber compositeChamber;
  EXPECT_EQ(0, compositeChamber.getMaxY());

  SuperLayer*  superLayer = new SuperLayer(&compositeChamber);
  compositeChamber.addSuperLayer(superLayer);
  EXPECT_EQ(0, compositeChamber.getMaxY());

  Layer* layer = new Layer(superLayer);
  superLayer->addLayer(layer);
  EXPECT_EQ(0, compositeChamber.getMaxY());

  compositeChamber.addXSize(10);
  compositeChamber.fillCells();
  EXPECT_EQ(1, compositeChamber.getMaxY());

  //Note: This does not actually add a cell;
  layer->fillCells(new Cell(0,0));
}
