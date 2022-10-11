
#include <iostream>
using namespace std;

int main () {

    cout << "\n\t====== Survey Produk ======\n" << endl;
    cout << "Mohon untuk masukan 25 input untuk pengembangan produk kami\n" << endl;
    
    char survey;
    double bagus = 0, tidak_bagus = 0, no_comment = 0; 
    int data_ke = 0;

    for (int s = 0; s < 25; s++) {

        cout << "Bagaiamana produk kami : " << endl;
        cout << "v = bagus" << endl;
        cout << "x = tidak bagus" << endl;
        cout << "o = no comment" << endl;

        cout << "\nInput anda : ";
        cin >> survey;

        if (survey == 'v' || survey == 'V') {
            bagus += 1;
            data_ke += 1;
        }
        else if (survey == 'x' || survey == 'X') {
            tidak_bagus += 1;
            data_ke += 1;
        }
        else if (survey == 'o' || survey == 'O') {
            no_comment += 1;
            data_ke += 1;
        }
        else {
            cout << "Error 211 : Input tidak sesuai" << endl;
            break;
        }

        cout << endl;

    }

    cout << "\n-----Persentase-----\n" << endl;
    cout << "Bagus       : " << (bagus/data_ke) * 100 << "%" << endl;
    cout << "Tidak bagus : " << (tidak_bagus/data_ke) * 100 << "%" << endl;
    cout << "No comment  : " << (no_comment/data_ke) * 100 << "%" << endl;

    cout << "\n********* Terima Kasih *********\n" << endl;

    return 0;

}