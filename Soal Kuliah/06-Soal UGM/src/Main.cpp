
#include <iostream>
using namespace std;

int main () {

    cout << "Menghitung hari dalam 1 bulan\n" << endl;

    int bulan;
    int tahun;

    cout << "Masukan bulan (1-12) : ";
    cin >> bulan;
    cout << "Masukan tahun        : ";
    cin >> tahun;

    cout << endl;

    if (bulan != 2 && bulan < 8 && bulan%2 != 0 || bulan >= 8 && bulan%2 == 0) { //bulan-bulan yang 31 hari         
        cout << "Jumlah hari adalah 31 hari" << endl;
    }
    else if (bulan != 2 && bulan < 8 && bulan%2 == 0 || bulan >= 8 && bulan%2 != 0) {
        cout << "Jumlah hari adalah 30 hari" << endl;
    }
    else if (bulan == 2 && tahun%4 == 0) {
        cout << "Jumlah hari adalah 29 hari" << endl;
    }
    else if (bulan == 2 && tahun%4 != 0) {
        cout << "Jumlah hari adalah 28 hari" << endl;
    }
    else {
        cout << "Error message : Input salah" << endl;
    }

    cout << endl;

    cout << endl;

    return 0;

}