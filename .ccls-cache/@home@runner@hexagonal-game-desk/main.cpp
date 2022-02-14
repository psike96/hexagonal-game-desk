#include <iostream>
#include ""
#include "Desk.h"

using namespace std;

int main() {

  Desk desk (4);
  Cell* c = desk.get_cell(0);
  int dir;

  cout << c->get_index() << endl << "Direction: ";
  cin >> dir;
  while (dir >= 0 && dir <=5) {
    c = c->get_next_cell(dir);
    cout << c->get_index() << endl;
    cout << "Direzione: ";
    cin >> dir;
  }

}