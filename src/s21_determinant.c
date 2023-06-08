#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (real_matrix(A)) {
    error = 1;
  } else if (A->columns != A->rows) {
    error = 2;
  } else {
    *result = get_determinant(A, A->rows);
  }
  return error;
}