#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (real_matrix(A) || real_matrix(B) || !result) {
    error = 1;
  } else {
    if ((A->rows != B->rows) && (A->columns != B->columns)) {
      error = 2;
    } else {
      error = s21_create_matrix(A->rows, A->columns, result);
      if ((A->rows == B->rows) && (A->columns == B->columns) && !error) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      } else {
        error = 2;
      }
    }
  }
  return error;
}