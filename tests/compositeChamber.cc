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

  SuperLayer* superLayer = compositeChamber.addSuperLayer();;
  EXPECT_EQ(0, compositeChamber.getMaxY());

  Layer* layer = superLayer->addLayer();
  EXPECT_EQ(0, compositeChamber.getMaxY());

  compositeChamber.addXSize(10);
  compositeChamber.fillCells();
  EXPECT_EQ(1, compositeChamber.getMaxY());
}

TEST(CompositeChamberTest, continuousIteration)
{
  CompositeChamber chamber(1);
  SuperLayer* superLayer = chamber.addSuperLayer();;
  Layer* layer = superLayer->addLayer();

  EXPECT_EQ(layer, chamber.deepFirst());

  ChamberIterator chamberIterator = chamber.first();
  EXPECT_EQ(nullptr, chamberIterator.current());

  chamber.fillCells();
  cout << "getMaxX" << chamber.getMaxX() << endl;
  chamber.visualize();
  auto cell = dynamic_cast<Cell*>(chamber.deepFirst());
  EXPECT_NE(nullptr, cell);
  cout << cell->visualize() << endl;
  chamberIterator = chamber.first();
  EXPECT_NE(nullptr, chamberIterator.current());

  cout << "Welcher Test schlaegt eigentlich fehl?" << endl;

  EXPECT_EQ(chamber.getCellAt(0, 0), chamberIterator.current());
  cout << "Der naechste" << endl;
  ++chamberIterator;
  cout << "Der vorige" << endl;
  EXPECT_EQ(chamber.getCellAt(1, 0), chamberIterator.current());

  chamber.addXSize(9);
  chamber.fillCells();

  chamberIterator = chamber.first();

  ++chamberIterator;
  EXPECT_EQ(chamber.getCellAt(1, 0), chamberIterator.current());


  /*    ChamberIterator chamberIterator = chamber.first();
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
      */
}

unsigned countHits(const CompositeChamber& chamber)
{
  /*
   unsigned counter = 0;
   for (ChamberIterator iter = chamber.first(); iter.current() != nullptr; ++iter) {
     if (iter.current()->getEDeposition() > 0) {
       counter++;
     }
   }
   return counter;*/
}

TEST(CompositeChamberTest, energyHandling)
{
  CompositeChamber chamber(10);
  SuperLayer* superLayer = chamber.addSuperLayer();;
  Layer* layer = superLayer->addLayer();
  chamber.fillCells();

  Cell* cell = chamber.getCellAt(2, 0);
  EXPECT_NE(nullptr, cell);
  EXPECT_EQ(0, cell->getMyY());
  EXPECT_TRUE(cell->xIsInside(2));

}

