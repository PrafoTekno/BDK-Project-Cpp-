
#include <iostream>
#include <string>

using namespace std;

int main () {

    cout << "======== Data Diri Sederhana ========\n\n" << endl;

    string nama;
    int tahun_lahir, tahun_saat_ini = 2022;
    int umur;

    cout << "Masukan nama panggilan anda : ";
    cin >> nama;

    cout << "Masukan tahun lahir anda    : ";
    cin >> tahun_lahir; 

    cout << "\n---------------------------------------\n" << endl;

    umur = tahun_saat_ini - tahun_lahir;

    cout << "Halo " << nama << " tahun ini kamu berumur " << umur << " tahun \\^.^/" << endl; 

    cout << endl;

    return 0;

}