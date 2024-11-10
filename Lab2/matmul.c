#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **random_matrix(int m, int n) {
    double **out = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        out[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            out[i][j] = ((double)rand() / RAND_MAX);
        }
    }
    return out;
}

double **matmul(double **A, double **B, int rows_out, int cols, int cols_out) {
    double **out = (double **)malloc(rows_out * sizeof(double *));
    for (int i = 0; i < rows_out; i++) {
        out[i] = (double *)malloc(cols_out * sizeof(double));
        for (int j = 0; j < cols_out; j++) {
            out[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                out[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return out;
}

int main() {
    srand(time(NULL));
    double time_sum = 0;

    for (int i = 0; i < 10; i++) {
        clock_t start_time = clock();
        double **randa = random_matrix(600, 100);
        double **randb = random_matrix(100, 600);
        double **mult = matmul(randa, randb, 600, 100, 600);
        clock_t end_time = clock();
        time_sum += (double)(end_time - start_time) / CLOCKS_PER_SEC;

        free(randa);
        free(randb);
        free(mult);
    }

    double average_time_c = (time_sum / 10);
    printf("%f\n", average_time_c);

    return 0;
}