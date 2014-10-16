#include <geometry/SpecialCell.h>
#include "gtest/gtest.h"

using namespace std;
//We want the special cell to be able to handle different colours.
//This is the first difference to the Cell.
TEST(SpecialCellTest, visualization)
{
  shared_ptr<ColourStrategy> colourStrategyBluePtr (new ColourStrategyBlue());
  shared_ptr<ColourStrategy> colourStrategyRedPtr  (new ColourStrategyRed() );
  SpecialCell specialCell (0,0, colourStrategyBluePtr);
  
  EXPECT_EQ("\x1B[97;44;1mO\x1B[0m", specialCell.visualize());
  specialCell.addEDeposition(1);
  EXPECT_EQ("\x1B[97;44;1mX\x1B[0m", specialCell.visualize());
  
  SpecialCell specialCell1 (0,0, colourStrategyRedPtr);
  EXPECT_EQ("\x1B[97;41;1mO\x1B[0m", specialCell1.visualize());
}