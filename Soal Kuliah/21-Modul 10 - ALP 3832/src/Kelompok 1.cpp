
#include <iostream>
#include <cmath>

using namespace std;

void statistik (int &, double &, double &);

int main () {

    cout << "\n\t======= Data Statistik =======\n" << endl;

    int banyak_nilai;
    double mean = 0, std_deviasi = 0;

    //Mengolah data RL

    cout << "Berapa banyak nilai RL yang hendak dimasukkan : ";
    cin >> banyak_nilai;
    statistik (banyak_nilai, mean, std_deviasi);
    cout << "\nRata-rata nilai RL adalah : " << mean << endl;
    cout << "Standard deviasi nilai RL adalah : " << std_deviasi << endl;

    cout << endl;

    //Mengolah data Algo

    cout << "Berapa banyak nilai Algo yang hendak dimasukkan : ";
    cin >> banyak_nilai;
    statistik (banyak_nilai, mean, std_deviasi);
    cout << "\nRata-rata nilai Algo adalah : " << mean << endl;
    cout << "Standard deviasi nilai Algo adalah : " << std_deviasi << endl;

    cout << endl;

    //Mengolah data Kalkulus

    cout << "Berapa banyak nilai Kalkulus yang hendak dimasukkan : ";
    cin >> banyak_nilai;
    statistik (banyak_nilai, mean, std_deviasi);
    cout << "\nRata-rata nilai Kalkulus adalah : " << mean << endl;
    cout << "Standard deviasi nilai Kalkulus adalah : " << std_deviasi << endl;

    cout << endl;

    return 0;

}

void statistik (int &num, double &val_mean, double &val_std) {

    //Variable cari mean
    double jumlah_mean = 0;

    //Variable cari std deviasi
    double nilai_kuadrat = 0;
    double sigma_std = 0;

    cout << "\nMasukan nilanya : " << endl;

    for (int i = 0; i < num; i++) {    
        cin >> val_mean;
        jumlah_mean = jumlah_mean + val_mean;

        nilai_kuadrat = val_mean * val_mean; //val_mean^2
        sigma_std = sigma_std + nilai_kuadrat;
    }

    val_mean = jumlah_mean/num; //Persamaan mean
    val_std = sqrt ((sigma_std-(pow (jumlah_mean,2)/num))/(num-1)); //Persamaan std deviasi

}