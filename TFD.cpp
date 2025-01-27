#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <cmath>
#include "gnuplot-iostream.h"

// Fonction pour calculer la TFD (version simplifiée)
std::vector<std::complex<double>> dft(const std::vector<std::complex<double>>& x) {
    int N = x.size();
    std::vector<std::complex<double>> X(N);

    for (int k = 0; k < N; ++k) {
        for (int n = 0; n < N; ++n) {
            X[k] += x[n] * std::exp(-2.0 * M_PI * std::complex<double>(0, 1) * k * n / N);
        }
    }

    return X;
}
