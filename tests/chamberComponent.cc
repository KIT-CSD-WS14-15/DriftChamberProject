#include <geometry/ChamberComponent.h>

#include "gtest/gtest.h"


TEST(ChamberComponentTest, childOps)
{
  ChamberComponent chamberComponent(0);
  EXPECT_EQ(nullptr, chamberComponent.getChild(0));
}
