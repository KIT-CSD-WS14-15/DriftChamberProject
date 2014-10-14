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

  vector<vector<unsigned> > houghSpace (15, vector<unsigned>(15));

  for (auto chamberIterator = chamber.first(); chamberIterator.current() != nullptr; ++chamberIterator){
	  auto cellPtr = chamberIterator.current();
	  if (cellPtr->getEDeposition() == 0) {
		  continue;
	  }

	  cout << "Start Hough procedure for a hit." << endl;
	  for (unsigned xShare = 0; xShare < houghSpace.size(); xShare++){

		  //Calculate current x-position (roughly):
		  float xPosition = static_cast<float>(xShare * chamber.getMaxX())/static_cast<float>(houghSpace.size());
		  cout << "xPosition: " << xPosition << endl;

		  //Calculate angle to cross current hit (vs. x-Axis):
		  float adjacent   = cellPtr->getXPosition() - xPosition;
		  cout << "adjacent: " << adjacent << endl;
		  cout << "yPosi : " << cellPtr -> getYPosition()<<endl;
		  float hypotenuse = sqrt((cellPtr->getYPosition()*cellPtr->getYPosition()) + (adjacent * adjacent));
		  cout << "hypo: " << hypotenuse << endl;
		  float angle = acos(adjacent / hypotenuse);
		  cout << "angle: " << angle * 180. / M_PI<< endl;
		  cout << (angle/M_PI)* houghSpace.size() << endl;

		  //Fill right bin:
		  houghSpace[xShare][static_cast<unsigned>((angle/M_PI)* houghSpace.size())]++;
	  }
  }

  //Find maximum
  unsigned maxXShare = 0;
  unsigned maxAngle  = 0;
  unsigned value     = 0;
  for (int ii = 0; ii < houghSpace.size(); ++ii){
	  for (int jj = 0; jj < houghSpace.size(); ++jj){
		  if(houghSpace[ii][jj] >= value){
			  value = houghSpace[ii][jj];
			  maxXShare = ii;
			  maxAngle  = jj;
		  }
	  }
  }

  cout << "Best Track Candidate at: " << endl
	   << "MaxXShare: " << maxXShare << endl
	   << "maxAngle: "  << maxAngle << endl
	   << "value: "     << value    << endl
	   << "X = " <<  static_cast<float>(maxXShare * chamber.getMaxX())/static_cast<float>(houghSpace.size()) << endl
	   << "Angle = " << static_cast<float>(maxAngle * 180.) /static_cast<float>(houghSpace.size()) << endl;

}
