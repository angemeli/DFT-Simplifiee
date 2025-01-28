#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <cmath>
#include <iomanip>

using namespace std;

// Fonction permettant de recueillir les données depuis le fichier contenant les signaux
void read_file(string file_name, vector<double> &signaux) {
    ifstream file(file_name); // Lecture du fichier

    double value;
    while (file >> value) {
        signaux.push_back(value); // Pour stocker les données dans un tableau dynamique
    }
    file.close();
}

// Fonction de calcul de la DFT Simplifiée
vector<complex<double>> dft(vector<double> &signaux) {
    vector<complex<double>> x(signaux.begin(), signaux.end()); //Conversion des données en nombres complexes
    int N = x.size();

    vector<complex<double>> X(N);
    // Calcul de la DFT
    for (int k = 0; k < N; k++) {
        for (int n = 0; n < N; n++) {
            X[k] += x[n] * exp(complex<double>(0, -2.0 * M_PI * k * n / N));
        }
    }

    return X;
}

// Fonction permettant d'afficher les résultats sous forme de diagramme en ASCII
void display_results() {

}

int main(int argc, char const *argv[]) {
    vector<double> signaux;
    string file_name = "valeurs.txt";

    read_file(file_name, signaux);

    vector<complex<double>> results = dft(signaux);

    return 0;
}
