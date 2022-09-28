
#include <iostream>

using namespace std;

double persentase (double status) { // Biar rapih rumus persentasenya
    double hasil = (status / 25) * 100;
    return hasil;
}

int main () {

    cout << "\t====== Survey Produk ======\n" << endl;

    int data_ke = 0;
    char kualitas;

    //Pengolahan data
    int bagus = 0, tidak_bagus = 0, no_comment = 0;

    while (data_ke < 25) {

        cout << "\n----- Bagaimana kualitas produknya -----" << endl;
        cout << "v = bagus" << endl;
        cout << "t = tidak bagus" << endl;
        cout << "n = no comment" << endl;
        
        cout << "\nInput kamu : ";
        cin >> kualitas;

        if (kualitas == 'v' || kualitas == 'V') {
            bagus += 1;
            data_ke ++;
        }
        else if (kualitas == 't' || kualitas == 'T') {
            tidak_bagus += 1;
            data_ke ++;
        }
        else if (kualitas == 'n' || kualitas == 'N') {
            no_comment += 1;
            data_ke ++;
        }
        else {
            cout << "Pesan Error : Input tidak tersedia!\n" << endl;
        }

    }

    cout << "\n\n^^^^^^ Persentase Survey ^^^^^^\n" << endl; 

    cout << "Ada " << bagus << " bagus\t   ---> " << persentase (bagus) << "%" << endl;
    cout << "Ada " << tidak_bagus << " tidak bagus  ---> " << persentase (tidak_bagus) << "%" << endl;
    cout << "Ada " << no_comment << " no comment   ---> " << persentase (no_comment) << "%" << endl;

    cout << endl;

    return 0;

}