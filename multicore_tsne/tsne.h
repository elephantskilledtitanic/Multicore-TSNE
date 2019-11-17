/*
 *  tsne.h
 *  Header file for t-SNE.
 *
 *  Created by Laurens van der Maaten.
 *  Copyright 2012, Delft University of Technology. All rights reserved.
 *
 *  Multicore version by Dmitry Ulyanov, 2016. dmitry.ulyanov.msu@gmail.com
 */


#ifndef TSNE_H
#define TSNE_H


static inline double sign(double x) { return (x == .0 ? .0 : (x < .0 ? -1.0 : 1.0)); }

template <class treeT, double (*dist_fn)( const DataPoint&, const DataPoint&)>
class TSNE
{
public:
    void run(double* X, int N, int D, double* Y,
               int no_dims = 2, double perplexity = 30, double theta = .5,
               int num_threads = 1, int max_iter = 1000, int n_iter_early_exag = 250,
               int random_state = 0, bool init_from_Y = false, int verbose = 0,
               double early_exaggeration = 12, double learning_rate = 200,
               double *final_error = NULL);
    void symmetrizeMatrix(int** row_P, int** col_P, double** val_P, int N);
private:
    double computeGradient(int* inp_row_P, int* inp_col_P, double* inp_val_P, double* Y, int N, int D, double* dC, double theta, bool eval_error);
    double evaluateError(int* row_P, int* col_P, double* val_P, double* Y, int N, int no_dims, double theta);
    void zeroMean(double* X, int N, int D);
    void computeGaussianPerplexity(double* X, int N, int D, int** _row_P, int** _col_P, double** _val_P, double perplexity, int K, int verbose);
    double randn();
    void first_step(double* X, int N, int D, int no_dims, double perplexity, double theta,
    int n_iter_early_exag, int verbose, int** _row_P, int** _col_P, double** _val_P);

    void second_step(int* row_P, int* col_P, double* val_P, double* X, int N, int D, double* Y,
            int no_dims, double perplexity, double theta, double eta, int verbose, int max_iter,
            double* dY, double* gains, double* uY, int stop_lying_iter, double early_exaggeration,
            int mom_switch_iter, double momentum, double final_momentum, double *final_error);
};

#endif

