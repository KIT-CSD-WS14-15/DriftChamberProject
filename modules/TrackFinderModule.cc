#include <modules/TrackFinderModule.h>

#include <geometry/Chamber.h>

#include <core/DataStore.h>

#include <memory>

using namespace std;

void TrackFinderModule::event()
{
  //get the geometry;
  shared_ptr<Chamber> myChamber = DataStore<Chamber>::Instance().getStorable("Chamber");

}
