#include <geometry/ChamberComponent.h>

#include "gtest/gtest.h"


TEST(ChamberComponentTest, childOps)
{
  ChamberComponent chamberComponent;
  EXPECT_EQ(nullptr, chamberComponent.getChild(0));

  chamberComponent.addChild(new ChamberComponent());
  EXPECT_NE(nullptr, chamberComponent.getChild(0));
}
