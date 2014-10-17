#include <modules/ParticleGunModule.h>
#include <core/DataStore.h>
#include <geometry/CompositeChamber.h>
#include <reconstruction/Particle.h>

#include <memory>
#include <iostream>
#include <random>
#include <cmath>

using namespace std;

void ParticleGunModule::event()
{
  shared_ptr<CompositeChamber> myChamber = DataStore<CompositeChamber>::Instance().getStorable("Chamber");

  //do the Tracking
  //Create a random Track, that will be stepped through the Chamber
  float pX = (rand() / static_cast<float>(RAND_MAX) - 0.5) * 2.;
  float pY =  rand() / static_cast<float>(RAND_MAX);

  //Lets limit the the x-position of the particle to the middle half.
  float chamberSizeX = static_cast<float>(myChamber->getMaxX());
  float x  = (((rand() / static_cast<float>(RAND_MAX)) * chamberSizeX) + (chamberSizeX / 2.)) / 2.;

  Particle particle(pX, pY, x);

  while (particle.getXPosition() < myChamber->getMaxX() && particle.getYPosition() < myChamber->getMaxY()) {
    //find nearest cell
    int xPosition = static_cast<unsigned>(particle.getXPosition());
    int yPosition = static_cast<unsigned>(particle.getYPosition());

    shared_ptr<Cell> myCellPtr = myChamber->getCellAt(xPosition, yPosition);
    if (myCellPtr) {
      myCellPtr->addEDeposition(1);
    }

    particle.makeStep();
  }

  std::cout << "Visualizing the Chamber after a Track passed." << std::endl;
  cout << "x    : " << x  << endl;
  cout << "Angle: " << acos(particle.getPX() / sqrt(pow(particle.getPY(), 2.) + pow(particle.getPX(), 2.)))
       * (180. / 3.14) << endl;

  myChamber->visualize();
}
