#include <geometry/Chamber.h>
#include <geometry/ChamberIterator.h>

using namespace std;

Chamber::Chamber(int nLayers) :
  ChamberComponent(0)
{
  if (nLayers >= 0) {
    m_cells = vector<vector<shared_ptr<Cell> > > (nLayers);
  }
}

ChamberIterator Chamber::first() const
{
  return ChamberIterator(this);
}

void Chamber::visualize() const
{
  //Print last layer first...
  for (auto layer = m_cells.rbegin(); layer != m_cells.rend(); ++layer) {
    //Each layer can be printed in standard order.
    for (auto & cell : *layer) {
      cout << cell->visualize();
    }
    cout << endl;
  }
}

void Chamber::addCell()
{
  //For all layers...
  for (unsigned ii = 0; ii < m_cells.size(); ++ii) {
    // ... place at the next available x position.
    unsigned xPosition = m_cells[0].size();

    if (ii < (m_cells.size() / 2)) {
      m_cells[ii].emplace_back(new SpecialCell(xPosition, ii,
                                               shared_ptr<ColourStrategy> (new ColourStrategyBlue())));
    } else {
      m_cells[ii].emplace_back(new SpecialCell(xPosition, ii,
                                               shared_ptr<ColourStrategy>(new ColourStrategyRed())));
    }
  }
}

void Chamber::cleanUp()
{
  for (ChamberIterator iter = first(); iter.current() != nullptr; ++iter) {
    iter.current()->resetEDeposition();
  }
}

std::shared_ptr<Cell> Chamber::getCellAt(unsigned xPosition, unsigned yPosition) const
{
  if (yPosition < m_cells.size() && xPosition < m_cells[0].size()) {
    return m_cells[yPosition][xPosition];
  }
  return nullptr;
}
