
#include <iostream>
#include <cmath>

using namespace std;

//Variable Global
double V_bangun_ruang;
int status = 0;

void milih_opsi (char tipe);
double luas_alas_lingkaran (double r);
double luas_alas_persegi (double s);

int main () {

    cout << "\n\t======== Menghitung Volume ========\n" << endl;

    char tipe_bangun_ruang;

    cout << "------ Bagun ruang ------\n" << endl;

    cout << "a = tabung" << endl;
    cout << "b = kerucut" << endl;
    cout << "c = kubus" << endl;
    cout << "d = limas segi empat" << endl;

    while (status < 1) {

        cout << "\nPilih bangun ruang yang ingin dihitung : ";
        cin >> tipe_bangun_ruang;

        milih_opsi (tipe_bangun_ruang);

    }

    cout << endl;

    cout << "Volume nya adalah " << V_bangun_ruang << " satuan^3" << endl;

    cout << endl;

    return 0;

}

void milih_opsi (char tipe) {

    // Buat bangun ruang
    double r, t, s;

    if (tipe == 'a' || tipe == 'b') {
        
        cout << "Masukan jari-jarinya : ";
        cin >> r;
        cout << "Masukan tingginya : ";
        cin >> t;

        if (tipe == 'a') {
            V_bangun_ruang = luas_alas_lingkaran (r) * t;
        }
        else {
            V_bangun_ruang = (luas_alas_lingkaran (r) * t)/3; 
        }

        status += 1;
        
    }

    else if (tipe == 'c' || tipe == 'd') {

        cout << "Masukan sisinya : ";
        cin >> s;

        if (tipe == 'c') {
            V_bangun_ruang = luas_alas_persegi (s) * s;
        }
        else {
            cout << "Masukan tingginya : ";
            cin >> t;
            V_bangun_ruang = (luas_alas_persegi (s) * t)/3;
        }

        status += 1;

    }

    else {
        cout << "Pesan error 143 : Input tidak sesuai" << endl;
    }

}

double luas_alas_lingkaran (double r) {

    double hasil = r * r * M_1_PI;
    return hasil; 

}

double luas_alas_persegi (double s) {

    double hasil = s * s;
    return hasil;

}