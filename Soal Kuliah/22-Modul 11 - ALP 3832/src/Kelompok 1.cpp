
#include <iostream>
#include <cmath>

using namespace std;

int main () {

    cout << "\n\t======== Mengurutkan Bilangan ========\n" << endl;

    // Variable

    const int Max = 10000; //nilai maximum untuk banykanya array
    
    int banyak_angka;    
    int angka[Max];

    // Menuliskan angka-angkanya

    cout << "Berapa banyak bilangan yang hendak diurutkan : ";
    cin >> banyak_angka;

    cout << "\nMasukan bilangan bulat tersebut : \n" << endl;

    for (int n = 0; n < banyak_angka; n++) {
        cin >> angka[n];
    }

    // Pengurutan angka

    int tampung_angka;

    for (int n = 0; n < banyak_angka; n++) { // Suku lebih awal
       
        for (int o = n+1; o < banyak_angka; o++) { // Suku lebih akhir
          
           if (angka[n] > angka[o]) { 

                tampung_angka = angka[n];
                angka[n] = angka[o];
                angka[o] = tampung_angka; // Menukar angka yang lebih besar jadi yang kecil
           
           }

        }

    }

    // Menampilkan angka

    cout << "\nHasil dari pengurutannya adalah : ";

    for (int n = 0; n < banyak_angka; n++) {
        cout << angka[n] << " ";
    }

    cout << endl << endl;

    return 0;

}