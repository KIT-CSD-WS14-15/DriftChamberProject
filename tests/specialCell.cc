#include <geometry/SpecialCell.h>
#include "gtest/gtest.h"

using namespace std;
//We want the special cell to be able to handle different colours.
//This is the first difference to the Cell.
TEST(SpecialCellTest, specialVisualization)
{
  const ColourStrategy* colourStrategyBluePtr(new ColourStrategyBlue());
  const ColourStrategy* colourStrategyRedPtr(new ColourStrategyRed());

  SpecialCell specialCell(0, 0, nullptr, colourStrategyBluePtr);

  EXPECT_EQ("\x1B[97;44;1m-\x1B[0m", specialCell.visualize());
  cout << "Blue Cell: " << specialCell.visualize() << endl;

  specialCell.addEDeposition(1);
  EXPECT_EQ("\x1B[97;44;1mX\x1B[0m", specialCell.visualize());

  SpecialCell specialCell1(0, 0, nullptr, colourStrategyRedPtr);
  EXPECT_EQ("\x1B[97;41;1m-\x1B[0m", specialCell1.visualize());
  cout << "Red Cell:  " << specialCell1.visualize() << endl;

  const WidthStrategy* widthStrategyTwoPtr(new WidthStrategyTwo());
  SpecialCell specialCell2(0, 0, nullptr, colourStrategyBluePtr, widthStrategyTwoPtr);
  EXPECT_EQ("\x1B[97;44;1m::\x1B[0m", specialCell2.visualize());

  specialCell2.addEDeposition(1);
  EXPECT_EQ("\x1B[97;44;1m><\x1B[0m", specialCell2.visualize());
}
