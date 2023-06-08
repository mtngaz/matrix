#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows <= 0 || columns <= 0 || !result) {
    error = 1;
  } else {
    result->matrix =
        malloc(rows * columns * sizeof(double) + rows * sizeof(double *));
    if (result->matrix) {
      result->rows = rows;
      result->columns = columns;
      double *ptr = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = ptr + columns * i;
      }
    }
  }
  return error;
}