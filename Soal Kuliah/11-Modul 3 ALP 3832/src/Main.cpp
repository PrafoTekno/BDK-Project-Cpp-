
/*
    ===========================
    Kelompok 1 : Salva dan Lego
    Modul 3 - ALP 3832
    ===========================
*/

#include <iostream>

using namespace std;

int main () {

    cout << "\t===== Pengurutan Bilangan =====\n\n" << endl;

    int a, b, c; //Variable bilangan 

    cout << "Masukan bilangan pertama : ";
    cin >> a;

    cout << "Masukan bilangan kedua : ";
    cin >> b;

    cout << "Masukan bilangan ketiga : ";
    cin >> c;

    int selisih_ab = a - b;
    int selisih_ac = a - c;
    int selisih_bc = b - c;

    if (a < b && b < c) {
        a = a;
        b = b;
        c = c;
    }
    else if (a < c && c < b) {
        a = a;
        b -= selisih_bc;
        c += selisih_bc;
    }
    else if (b < a && a < c) {
        a -= selisih_ab;
        b += selisih_ab;
        c = c;
    }
    else if (b < c && c < a) {
        a -= selisih_ab;
        b -= selisih_bc;
        c += selisih_ac;
    }
    else if (c < a && a < b) {
        a -= selisih_ac;
        b += selisih_ab;
        c += selisih_bc;
    } 
    else {
        a -= selisih_ac;
        b = b;
        c += selisih_ac;
    }

    cout << "\n----------------------------- Diurutkan -----\n" << endl;
    cout << "Hasil : " << a << ", " << b << ", " << c << endl;

    cout << endl;

    return 0;

}