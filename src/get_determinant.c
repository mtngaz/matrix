#include "s21_matrix.h"

double get_determinant(matrix_t *matrix, int size) {
  double det = 0.0;
  int degree = 1;
  if (size == 1) {
    return matrix->matrix[0][0];
  } else if (size == 2) {
    return matrix->matrix[0][0] * matrix->matrix[1][1] -
           (matrix->matrix[0][1] * matrix->matrix[1][0]);
  } else if (size > 2) {
    matrix_t new_matrix = {0};
    for (int j = 0; j < size; j++) {
      create_minor(matrix, size, 0, j, &new_matrix);
      det += degree *
             (matrix->matrix[0][j] * get_determinant(&new_matrix, size - 1));
      degree *= (-1);
      s21_remove_matrix(&new_matrix);
    }
  }
  return det;
}