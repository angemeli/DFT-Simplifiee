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

    cout << "\nLes valeurs suivantes ont ete recuperees depuis le fichier texte :\n";
    for (int i = 0; i < signaux.size(); i++) {
        cout << "\033[32m" << signaux[i] << "\033[37m    ";
    }
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

    cout << "\n\nLe calcul de la DFT est termine. Les resultats seront affiches sous forme de diagramme\n";
    return X;
}

// Fonction permettant d'afficher les résultats sous forme de diagramme en ASCII
void display_results(vector<double> &signaux, const vector<complex<double>> &results) {
    int max_amplitude = 0;
    
    // Trouver l'amplitude maximale pour la normalisation
    for (const auto &c : results) {
        int amplitude = static_cast<int>(abs(c));
        if (amplitude > max_amplitude) {
            max_amplitude = amplitude;
        }
    }

    // Affichage des amplitudes sous forme de diagramme ASCII
    cout << "\nDiagramme des amplitudes (les valeurs élevées sont affichées en rouge) :" << "\n\n";

    for (int i = 0; i < results.size(); ++i) {
        int amplitude = abs(results[i]);
        int bar_length = amplitude * 50 / max_amplitude; // Normaliser à une longueur de 50 caractères
        cout << setw(3) << i+1 << " : ";
        // Détection de pics
        if (amplitude > 10) {
            cout << "\033[31m" << string(bar_length, '-') << " (" << amplitude << ")" << "\033[37m\n";
        }
        else {
            cout << string(bar_length, '-') << " (" << amplitude << ")" << "\n";
        }
    }

    cout << "\nCorrespondance des signaux : \n";
    for (int i = 0; i < signaux.size(); i++) {
        cout << i+1 << " -> " << signaux[i] <<"\n";
    }
}

int main(int argc, char const *argv[]) {
    cout << "\nBienvenue dans ce programme. \nL'objectif est de calculer la DFT pour un ensemble de signaux et d'afficher les resultats sous forme de diagramme en console.\n";
    vector<double> signaux;
    string file_name = "valeurs.txt";

    read_file(file_name, signaux);

    vector<complex<double>> results = dft(signaux);

    display_results(signaux, results);

    return 0;
}

    vector<complex<double>> results = dft(signaux);

    return 0;
}
