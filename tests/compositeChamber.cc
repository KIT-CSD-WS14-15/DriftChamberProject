#include <geometry/Cell.h>
#include <geometry/Layer.h>
#include <geometry/SuperLayer.h>
#include <geometry/CompositeChamber.h>

#include "gtest/gtest.h"

using namespace std;

TEST(CompositeChamberTest, chamberConstruction)
{
  CompositeChamber compositeChamber;
  EXPECT_EQ(0, compositeChamber.getMaxY());

  shared_ptr<SuperLayer> superLayer = compositeChamber.addSuperLayer();;
  EXPECT_EQ(0, compositeChamber.getMaxY());

  shared_ptr<Layer> layer = superLayer->addLayer();
  EXPECT_EQ(0, compositeChamber.getMaxY());

  compositeChamber.addXSize(10);
  compositeChamber.fillCells();
  EXPECT_EQ(1, compositeChamber.getMaxY());

  //Note: This does not actually add a cell;
  layer->fillCells(new Cell(0,0));
}
