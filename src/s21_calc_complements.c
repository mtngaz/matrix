#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (real_matrix(A)) {
    error = 1;
  } else if (A->columns != A->rows) {
    error = 2;
  } else {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (!error) {
      create_complements_matrix(A, result);
    }
  }
  return error;
}