#include <ParticleGunModule.h>
#include <DataStore.h>
#include <Chamber.h>
#include <Particle.h>

#include <memory>
#include <iostream>
#include <random>

using namespace std;

void ParticleGunModule::event()
{
  shared_ptr<Chamber> myChamber = DataStore<Chamber>::Instance().getStorable("Chamber");

  //do the Tracking
  //Create a random Track, that will be stepped through the Chamber
  float pX = rand()/static_cast<double>(RAND_MAX);
  float pY = rand()/static_cast<double>(RAND_MAX);
  Particle particle(pX, pY);

  cout << "pX = " << particle.getPX() << endl;
  cout << "pY = " << particle.getPY() << endl;

  while (particle.getXPosition() < myChamber->getMaxX() && particle.getYPosition() < myChamber->getMaxY()){
	  //find nearest cell
	  int xPosition = static_cast<unsigned>(particle.getXPosition()+0.5);
	  int yPosition = static_cast<unsigned>(particle.getYPosition()+0.5);

	  shared_ptr<Cell> myCellPtr = myChamber->getCellAt(xPosition, yPosition);
	  if (myCellPtr) {
		  myCellPtr->addEDeposition(1);
	  }

	  particle.makeStep();
  }

  std::cout << "Visualizing the Chamber after a Track passed." << std::endl;
  myChamber->visualize();
}
