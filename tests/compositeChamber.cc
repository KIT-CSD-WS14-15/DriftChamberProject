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

TEST(ChamberTest, chamberConstruction)
{
  Chamber chamber;
  EXPECT_EQ(4, chamber.getMaxY());

  Chamber chamber1(8);
  EXPECT_EQ(8, chamber1.getMaxY());

  //As I haven't yet added any cells, I expect the iterator to
  //point to nullptr from the beginning.
  EXPECT_EQ(nullptr, chamber.first().current());
  EXPECT_EQ(0, chamber.getMaxX());


  chamber.addCell();
  EXPECT_NE(nullptr, chamber.first().current());
  EXPECT_EQ(1, chamber.getMaxX());
}

TEST(ChamberTest, continuousIteration)
{
  Chamber chamber(10);
  chamber.addCell();
  ChamberIterator chamberIterator = chamber.first();
  for (unsigned ii = 0; ii < chamber.getMaxY(); ++ii) {
    EXPECT_EQ(ii + 0.5, chamberIterator.current()->getYPosition());
    ++chamberIterator;
  }
  EXPECT_EQ(nullptr, chamberIterator.current());

  Chamber chamber1(2);
  chamber1.addCell();
  chamber1.addCell();
  chamber1.addCell();
  ChamberIterator chamberIterator1 = chamber1.first();
  EXPECT_EQ(chamber1.getCellAt(0, 0), chamberIterator1.current());
  ++chamberIterator1; ++chamberIterator1;
  EXPECT_EQ(chamber1.getCellAt(2, 0), chamberIterator1.current());
  ++chamberIterator1; ++chamberIterator1;
  EXPECT_EQ(chamber1.getCellAt(1, 1), chamberIterator1.current());
}

unsigned countHits(const Chamber& chamber)
{
  unsigned counter = 0;
  for (ChamberIterator iter = chamber.first(); iter.current() != nullptr; ++iter) {
    if (iter.current()->getEDeposition() > 0) {
      counter++;
    }
  }
  return counter;
}

TEST(ChamberTest, energyHandling)
{
  Chamber chamber(10);
  chamber.addCell(); chamber.addCell();
  EXPECT_EQ(0, countHits(chamber));

  chamber.getCellAt(1, 8)->addEDeposition(1);

  EXPECT_EQ(1, countHits(chamber));

  chamber.cleanUp();
  EXPECT_EQ(0, countHits(chamber));

}

