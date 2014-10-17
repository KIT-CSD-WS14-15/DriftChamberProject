#include <modules/TrackFinderModule.h>

#include <geometry/CompositeChamber.h>

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
  const CompositeChamber& chamber = *(DataStore<CompositeChamber>::Instance().getStorable("Chamber").get());

  //Define the Hough plane:
  unsigned dimension = 30;

  auto myTuple = findMaximum(voteHough(chamber, dimension), chamber);
  cout << "Best Track Candidate at: "  << endl
       << "value: "  << get<0>(myTuple) << endl
       << "X = "     << get<1>(myTuple) << endl
       << "Angle = " << get<2>(myTuple) << endl;
}


vector<vector<unsigned> > TrackFinderModule::voteHough(const CompositeChamber& chamber,
                                                       unsigned houghDimension)
{
  vector<vector<unsigned> > houghSpace(houghDimension, vector<unsigned>(houghDimension , 0));
  for (auto chamberIterator = chamber.first();
       chamberIterator.current() != nullptr; ++chamberIterator) {
    auto cellPtr = chamberIterator.current();
    if (cellPtr->getEDeposition() == 0) {
      continue;
    }

    for (unsigned xShare = 0; xShare < houghSpace.size(); xShare++) {

      //Calculate current x-position (roughly):
      float xPosition = static_cast<float>(xShare * chamber.getMaxX())
                        / static_cast<float>(houghSpace.size());

      //Calculate angle to cross current hit (vs. x-Axis):
      float adjacent = cellPtr->getXPosition() - xPosition;
      float hypotenuse = sqrt(
                           (cellPtr->getYPosition() * cellPtr->getYPosition())
                           + (adjacent * adjacent));
      float angle = acos(adjacent / hypotenuse);

      //Fill right bin:
      houghSpace[xShare][static_cast<unsigned>((angle / M_PI) * houghSpace.size())]++;
    }
  }
  return houghSpace;
}

tuple<unsigned, float, float>
TrackFinderModule::findMaximum(const vector<vector<unsigned> >& houghSpace,
                               const CompositeChamber& chamber)
{
//Find maximum
  unsigned maxXShare = 0;
  unsigned maxAngle = 0;
  unsigned value = 0;
  for (int ii = 0; ii < houghSpace.size(); ++ii) {
    for (int jj = 0; jj < houghSpace.size(); ++jj) {
      if (houghSpace[ii][jj] >= value) {
        value = houghSpace[ii][jj];
        maxXShare = ii;
        maxAngle = jj;
      }
    }
  }

  float x     = static_cast<float>(maxXShare * chamber.getMaxX())
                / static_cast<float>(houghSpace.size());
  float angle = static_cast<float>(maxAngle * 180.)
                / static_cast<float>(houghSpace.size());

  return make_tuple(value, x, angle);
}
