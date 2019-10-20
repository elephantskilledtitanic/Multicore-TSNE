#include <cstdio>
#include <cstdlib>

#include "tsne_lib.h"

static inline double randD() {
    return (double)rand() / (double)((unsigned)RAND_MAX + 1);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <N> <D> <no_dims> <random_state>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int D = atoi(argv[2]);
    int no_dims = atoi(argv[3]);
    int random_state = atoi(argv[4]);

    double *X = (double *)malloc(N * D * sizeof(double));
    if (!X) {
        printf("Could not allocate memory for X");
        return 1;
    }

    double *Y = (double *)malloc(N * no_dims * sizeof(double));
    if (!X) {
        printf("Could not allocate memory for Y");
        return 1;
    }

    // Initialize X
    srand(random_state);
    for (int i = 0; i < N * D; i++)
        X[i] = randD();

    double perplexity = 30.0;
    double theta = .5;
    int num_threads = 1;
    int max_iter = 1000;
    int n_iter_early_exag = 250;
    int init_from_Y = false;
    int verbose = 0;
    double early_exaggeration = 12;
    double learning_rate = 200;
    double *final_error = NULL;
    int distance = 1;

    tsne_run_double(
        X, N, D, Y, no_dims, perplexity, theta, num_threads, max_iter, n_iter_early_exag,
        -1, init_from_Y, verbose, early_exaggeration, learning_rate, final_error, distance
    );

    return 0;
}
