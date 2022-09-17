
#include <iostream>
#include <string>

using namespace std;

string tipe_film;

void Menonton (double uang) {

    int umur;
    char status_pergi;

    cout << "Masukan umur anda : ";
    cin >> umur;

    if (umur < 16) {
        
        cout << "Anda pergi dengan orang tua? (y/n) : ";
        cin >> status_pergi;

        if (umur < 13) {
            if (status_pergi == 'y') {
                tipe_film = "G, PG";
            }
            else {
                tipe_film = "G";
            }
        }
        else if (umur >= 13) {
            tipe_film = "G, PG";
        }
        else {
            tipe_film = "G, PG, R";
        }

    }

    else {
        tipe_film = "G, PG, R";
    }

}

double uang_pinjaman (double selisih, double modal) {
    return selisih + modal;
}

void Mengutang (double selisih_uang) {

    int no_rek;

    cout << "\nBaik tuliskan no rekening anda : ";
    cin >> no_rek; 

    cout << "Sebesar $ " << selisih_uang << " akan di transfer ke " << no_rek << endl;

}   

int main () {

    cout << "\t======= Bioskop Konoha =======\n\n" << endl;

    int umur; 
    double uang_saku, selisih_uang;
    char status_bayar;

    cout << "Masukan jumlah uang saku anda : $ ";
    cin >> uang_saku;

    selisih_uang = 7.50 - uang_saku;

    if (uang_saku >= 7.50) {
        Menonton (uang_saku);
    }

    else {
        cout << "\nMaaf uang saku anda tidak cukup untuk menonton film" << endl;
        cout << "Apakah anda ingin menambahkan $ " << selisih_uang << " untuk dapat menonton film (y/n) : ";
        cin >> status_bayar;

        if (status_bayar == 'y') {
            Mengutang (selisih_uang);
            Menonton (uang_pinjaman (selisih_uang, uang_saku));
        }
        else {
            cout << "\nSampai jumpa!" << endl;
        }

    }

    cout << "\n----------------------------------------------------------\n" << endl;

    cout << "Tipe film yang bisa anda tonton adalah : " << tipe_film << endl;

    cout << endl;

    return 0;

}