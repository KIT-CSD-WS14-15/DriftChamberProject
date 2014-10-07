#pragma once
#include <DataStore.h>
#include <Chamber.h>
#include <memory>
#include <iostream>

/** Shoot a particle through the Chamber.
 *
 *  The particle follows some curvature and Cells, that are hit
 *  get potentially an energy deposition and a drift time assigned.
 *
 *  Example:
 *  Cell:
 *  OOOOOOOOOO
 *  OOOOOOOOOO
 *      P      Particle Position
 *
 *  OOOOOOOOOO
 *  OOOOOXPOOO
 *      X
 *
 *  OOOOOOOXPO
 *  OOOOOXXOOO
 *      X
 *
 *  Final Cell Setup in that event.
 *  OOOOOOOXXO
 *  OOOOOXXOOO
 *      X
 *
 *  Currently only straight lines are implemented as paths of particles.
 */
class ParticleGunModule : public Module {
public:
	void begin() override {
      std::shared_ptr<Chamber> myChamber = DataStore<Chamber>::Instance().getStorable("Chamber");

      std::cout << "Another times visualizing the Chamber" << std::endl;
      myChamber->visualize();
	}

	void event() override {
		//do the Tracking
	}

};
