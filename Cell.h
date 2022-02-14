#ifndef CELL_H_
#define CELL_H_

/*       0:N
      --------
5:NW /        \  1:NE
    /          \
    \          /
4:SW \        /  2:SE
      --------
         3:S
*/

class Cell {
  static int numberofcells;
  const int index;
  Cell* next_cells[6];
public:
  Cell ();
  Cell* get_next_cell (int direction);
  void connect(Cell* c, int direction);
  int get_index();
};

#endif /*CELL_H_*/