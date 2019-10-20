extern "C"
{
    #ifdef _WIN32
    __declspec(dllexport)
    #endif
    extern void tsne_run_double(double* X, int N, int D, double* Y,
                                int no_dims = 2, double perplexity = 30, double theta = .5,
                                int num_threads = 1, int max_iter = 1000, int n_iter_early_exag = 250,
                                int random_state = -1, bool init_from_Y = false, int verbose = 0,
                                double early_exaggeration = 12, double learning_rate = 200,
                                double *final_error = NULL, int distance = 1);
}