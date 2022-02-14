#ifndef DESK_H_
#define DESK_H_

#include <vector>
#include <cmath>
#include "Cell.h"

class Desk {
  const int size;
  std::vector<Cell*> cells;
  // Dato l'indice i della cella restituisce il layer a cui la stessa appartiene
  static int i_layer(int i);
  // Dato il layer l, restituisce l'indice minimo della cella tra quelle presenti nello stesso layer
  static int layer_iMin(int l);
  // Dato il layer l, restituisce l'indice massimo della cella tra quelle presenti nello stesso layer
  static int layer_iMax(int l);
  // Dato il numero di celle n presenti su un lato (vertici compresi), restituisce il numero totale di celle necessarie per creare il tavolo
  static int cells_calc(int n);
  // Dato l'indice della cella i, restituisce true se essa costituisce un vertice del layer a cui appartiene, false altrimenti
  static bool is_angle(int i);
  // Dato l'indice della cella-vertice i, restituisce il vertice a cui appartiene (intervallo [0,5])
  static int angle(int i);
  static int i_th_angle_of_layer(int a, int l);
public:
  Desk(int size);
  virtual ~Desk();
  Cell* get_cell(int index);
};

#endif /*DESK_H_*/