#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void convolution(int* A, int NA, int* F, int NF, long long int* output) {
    for (int i = 0; i < NA - NF + 1; i++) {
        output[i] = 0;
        for (int j = 0; j < NF; j++) {
            output[i] += A[i + j] * F[NF-j-1];
        }
    }
}

int main() {
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = (int*)malloc(sizeof(int) * NA);
    int *F = (int*)malloc(sizeof(int) * NF);

    for (int i = 0; i < NA; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < NF; i++) {
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc ----

    long long int outputSize = NA - NF + 1;
    long long int* output =  (long long int*)malloc(sizeof(long long int) * outputSize);

    double start_time = omp_get_wtime();
    convolution(A, NA, F, NF, output);
    double time = omp_get_wtime() - start_time;
    printf("time: %f seconds\n", time);
    
    // for (int i = 0; i < outputSize; i++) {
    //     printf("%lli\n", output[i]);
    // }


    // ---- free memory ----
    free(F);
    free(A);
    free(output);
    // ---- end free ----
    return 0;
}
