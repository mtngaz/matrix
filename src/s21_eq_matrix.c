#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if (real_matrix(A) || real_matrix(B)) {
    error = FAILURE;
  } else if ((A->rows == B->rows) && (A->columns == B->columns)) {
    int flag = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) {
          error = FAILURE;
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        break;
      }
    }
  } else {
    error = FAILURE;
  }
  return error;
}