#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (real_matrix(A)) {
    error = 1;
  } else if (A->rows != A->columns) {
    error = 2;
  } else {
    double det = 0.0;
    s21_determinant(A, &det);
    if (fabs(det) < 1e-6) {
      error = 2;
    }
    matrix_t complements = {0};
    matrix_t invers = {0};

    int size = A->rows;
    s21_create_matrix(size, size, result);

    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &invers);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        result->matrix[i][j] = invers.matrix[i][j] / det;
      }
    }
    s21_remove_matrix(&invers);
    s21_remove_matrix(&complements);
  }
  return error;
}