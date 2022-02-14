#include "Cell.h"

Cell::Cell () : index(numberofcells++) {}

Cell* Cell::get_next_cell (int direction) {
  return next_cells[direction%6];
}

void Cell::connect(Cell* c, int direction) {
  this->next_cells[direction%6] = c;
  c->next_cells[(direction+3)%6] = this;
}

int Cell::get_index() {
  return index;
}

int Cell::numberofcells = 0;