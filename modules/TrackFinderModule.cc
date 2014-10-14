#include <modules/TrackFinderModule.h>

#include <geometry/Chamber.h>
#include <geometry/ChamberIterator.h>

#include <core/DataStore.h>

#include <memory>
#include <vector>
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <algorithm>

using namespace std;

void TrackFinderModule::event()
{
  //get the geometry;
  const Chamber& chamber = *(DataStore<Chamber>::Instance().getStorable("Chamber").get());

  //Define the Hough plane:
  unsigned dimension = 30;
  vector<vector<unsigned> > houghSpace(dimension, vector<unsigned>(dimension ,0));

  for (auto chamberIterator = chamber.first(); chamberIterator.current() != nullptr; ++chamberIterator) {
    auto cellPtr = chamberIterator.current();
    if (cellPtr->getEDeposition() == 0) {
      continue;
    }

    for (unsigned xShare = 0; xShare < houghSpace.size(); xShare++) {

      //Calculate current x-position (roughly):
      float xPosition = static_cast<float>(xShare * chamber.getMaxX()) / static_cast<float>(houghSpace.size());

      //Calculate angle to cross current hit (vs. x-Axis):
      float adjacent   = cellPtr->getXPosition() - xPosition;
      float hypotenuse = sqrt((cellPtr->getYPosition() * cellPtr->getYPosition()) + (adjacent * adjacent));
      float angle = acos(adjacent / hypotenuse);

      //Fill right bin:
      houghSpace[xShare][static_cast<unsigned>((angle / M_PI)* houghSpace.size())]++;
    }
  }

  //Find maximum
  unsigned maxXShare = 0;
  unsigned maxAngle  = 0;
  unsigned value     = 0;
  for (int ii = 0; ii < houghSpace.size(); ++ii) {
    for (int jj = 0; jj < houghSpace.size(); ++jj) {
      if (houghSpace[ii][jj] >= value) {
        value = houghSpace[ii][jj];
        maxXShare = ii;
        maxAngle  = jj;
      }
    }
  }

  cout << "Best Track Candidate at: " << endl
       << "value: "     << value    << endl
       << "X = " <<  static_cast<float>(maxXShare * chamber.getMaxX()) / static_cast<float>(houghSpace.size()) << endl
       << "Angle = " << static_cast<float>(maxAngle * 180.) / static_cast<float>(houghSpace.size()) << endl;

}
