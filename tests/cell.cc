#include <geometry/Cell.h>
#include "gtest/gtest.h"

TEST(CellTest, energyHandling)
{
  Cell cell(0, 0);
  EXPECT_EQ(0, cell.getEDeposition());
}

TEST(CellTest, positionalHandling)
{
  Cell cell(0, 0);
  EXPECT_EQ(0.5, cell.getXPosition());
  EXPECT_EQ(0.5, cell.getYPosition());
}
