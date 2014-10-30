#include <geometry/Cell.h>
#include <reconstruction/BackgroundVisitor.h>

void Cell::accept(BackgroundVisitor& backgroundVisitor)
{
  backgroundVisitor.visitCell(this);
}
