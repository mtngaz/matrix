#include "s21_matrix.h"

int real_matrix(matrix_t *A) {
  int res = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    res = 1;
  }
  return res;
}