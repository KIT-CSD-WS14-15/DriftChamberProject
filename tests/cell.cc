#include <geometry/Cell.h>
#include "gtest/gtest.h"

TEST(CellTest, energyHandling)
{
  Cell cell(0, 0);
  EXPECT_EQ(0, cell.getEDeposition());

  cell.addEDeposition(4);
  EXPECT_EQ(4, cell.getEDeposition());

  cell.addEDeposition(1);
  EXPECT_EQ(5, cell.getEDeposition());

  cell.resetEDeposition();
  EXPECT_EQ(0, cell.getEDeposition());
}

TEST(CellTest, positionalHandling)
{
  // Constructor and position getter.
  Cell cell(0, 0);
  EXPECT_EQ(0.5, cell.getXPosition());
  EXPECT_EQ(0.5, cell.getYPosition());

  Cell cell1(0, 1);
  EXPECT_EQ(0.5, cell1.getXPosition());
  EXPECT_EQ(1.5, cell1.getYPosition());

  Cell cell2(1, 0);
  EXPECT_EQ(1.5, cell2.getXPosition());
  EXPECT_EQ(0.5, cell2.getYPosition());
}

TEST(CellTest, visualization)
{
  Cell cell(0,0);
  EXPECT_EQ("\x1B[97;40;1mO\x1B[0m", cell.visualize());

  cell.addEDeposition(1);
  EXPECT_EQ("\x1B[97;40;1mX\x1B[0m", cell.visualize());
}
