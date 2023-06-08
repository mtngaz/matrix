#include "s21_matrix.h"

int create_minor(matrix_t *A, int size, int row, int column, matrix_t *B) {
  int res = 0;
  int offset_row = 0;
  int offset_column = 0;
  res = s21_create_matrix(size - 1, size - 1, B);
  if (!res) {
    for (int i = 0; i < size - 1; i++) {
      if (i == row) {
        offset_row = 1;
      }
      offset_column = 0;
      for (int j = 0; j < size - 1; j++) {
        if (j == column) {
          offset_column = 1;
        }
        B->matrix[i][j] = A->matrix[i + offset_row][j + offset_column];
      }
    }
  }
  return res;
}