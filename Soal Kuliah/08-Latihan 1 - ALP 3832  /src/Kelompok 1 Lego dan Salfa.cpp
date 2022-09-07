
#include <iostream>

using namespace std;

int main () {

    //Judul 
    cout << "====== Indentitas Sederhana ======\n\n" << endl;

    //Variable yang dibutuhkan 
    char initial = 's';
    int tahun_lahir, tahun_saat_ini = 2022;

    //Memasukan pertanyaan beserta inputnya
    cout << "Masukan inisial nama kamu : ";
    cin >> initial;
    cout << "Maukan tahun lahir kamu   : ";
    cin >> tahun_lahir;

    //Rumus umur
    int umur = tahun_saat_ini - tahun_lahir;

    cout << "\n----------------------------------\n" << endl;

    //Meng-output kan semua input
    cout << "Halo \"" << initial << "\"! Tahun ini kamu berumur " << umur << " tahun \\^.^/" << endl;

    cout << endl;
    
    return 0;

}