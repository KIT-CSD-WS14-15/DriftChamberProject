#include <geometry/Chamber.h>
#include <geometry/ChamberIterator.h>

ChamberIterator Chamber::first() const
{
  return ChamberIterator(this);
}
