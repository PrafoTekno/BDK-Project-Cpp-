
#include <iostream>
#include <cmath>

using namespace std;

const int nilai_max = 100;

int main () {

    cout << "===== Pengelolaan Data =====\n\n" << endl;

    // Variable yang dibutuhkan
    
    int n = 0; // buat banyak data 
    double data [nilai_max];

    cout << "Berapa banyak data yang akan di olah : ";
    cin >> n;

    cout << "\nMasukan data nya : \n" << endl;

    for (int s = 0; s < n; s++) {
        cin >> data[s];
    }

    double jumlah_data = 0;

    for (int s = 0; s < n; s++) { 
        jumlah_data = jumlah_data + data[s];
    }

    cout << "\nJumlah data = " << jumlah_data << endl;

    cout << "\n----------------------------------------\n" << endl;

    // Pengelolaan lanjutan 

    double mean;
    double sigma;

    mean = jumlah_data / n;

    for (int i = 0; i < n; i++) {
        sigma = pow ((data[i] - mean), 2);
    }

    double variance;
    double deviasi;

    variance = sigma * 1/n;
    deviasi = sqrt (variance);

    cout << "\nMean = " << mean << endl;
    cout << "Varians = " << variance << endl;
    cout << "Standard Deviasi = " << deviasi << endl;

    cout << endl;

    return 0;

}