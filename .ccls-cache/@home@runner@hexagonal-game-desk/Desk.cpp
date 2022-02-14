#include <vector>
#include <cmath>
#include "Desk.h"
#include "Cell.h"

/*        ______
         /      \
  ______/   1    \______
 /      \        /      \
/   6    \______/   2    \
\        /      \        /
 \______/   0    \______/
 /      \        /      \
/   5    \______/   3    \
\        /      \        /
 \______/   4    \______/
        \        /
         \______/
*/

inline int Desk::i_layer(int i) {
  return ceil((-3+sqrt(9+12*i))/6);
}

inline int Desk::layer_iMin(int l) {
  return l == 0 ? 0 : 3*l*(l-1)+1;
}

inline int Desk::layer_iMax(int l) {
  return 3*l*(l+1);
}

inline int Desk::cells_calc(int n) {
  return 3*n*(n-1)+1;
}

inline bool Desk::is_angle(int i) {
  auto l = i_layer(i);
  auto i_min = layer_iMin(l);
  return (i-i_min)%l==0;
}

inline int Desk::angle(int i) {
  auto l = i_layer(i);
  auto i_min = layer_iMin(l);
  return (i-i_min)/l;
}

inline int Desk::i_th_angle_of_layer(int a, int l) {
  auto i_min = layer_iMin(l);
  return i_min + a*l;
}

Desk::Desk(int size) : size(size) {
  auto cells_number = cells_calc(size);
  for (int i = 0; i < cells_number; i++)
    cells.push_back(new Cell);

  int i_next;
  int i_previous_l;
  int iMin = 0, iMax = 0;
  int iMin_previous_l, iMax_previous_l;
  int direction = 1;
  int layer_max = size - 1;
  for (int l = 1; l <= layer_max; l++) {
    iMin_previous_l = iMin; iMax_previous_l = iMax;
    iMin = layer_iMin(l); iMax = layer_iMax(l);
    for (int i = iMin; i <= iMax; i++) {
      i_next = iMin + (i+1-iMin)%(iMax-iMin+1);
      if (is_angle(i)) {
        direction = (direction+1)%6;
        cells[i]->connect(cells[i_next], direction);
        i_previous_l = i_th_angle_of_layer(angle(i),l-1);
        cells[i]->connect(cells[i_previous_l], direction+1);
      }
      else {
        cells[i]->connect(cells[i_next], direction);
        Cell* c2 = cells[i-1]->get_next_cell(direction+1);
        Cell* c1 = c2->get_next_cell(direction);
        cells[i]->connect(c1, direction+1);
        cells[i]->connect(c2, direction+2);
      }
    }
  }
}

Desk::~Desk() {
  for (auto cell : cells)
    delete cell;
}

Cell* Desk::get_cell(int index) {
  return cells.at(index);
}