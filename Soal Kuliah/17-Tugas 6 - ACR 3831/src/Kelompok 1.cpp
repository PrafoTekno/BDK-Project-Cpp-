
#include <iostream>

using namespace std;

int main () {

    cout << "\n\t======= Menebak Bilangan Bulat ======\n" << endl;

    //Variable yang dibutuhkan

    int bil_asli = 24;
    int bil_tebak, clue = 0;

    for (int i = 0; i < 3; i++) {

        cout << endl;

        cout << "Masukan sebuah bilbul : ";
        cin >> bil_tebak;

       if (bil_asli == bil_tebak) {
            cout << "Selamat tebakan kamu benar" << endl;
            break;
        }
        else if (i == 1) {
            clue = bil_asli - bil_tebak;
            cout << "Angkanya itu adalah " << clue << " dari jawaban kamu" << endl; 
        }
        else if (i == 2) {
            cout << "Kamu gagal dalam menebak angkanya, silahkan coba lagi nanti" << endl;
        }
        else {
            cout << "" << bil_tebak << " bukanlah angka yang dimaksud" << endl;
        }

    }

    cout << "\n---------------- Terima kasih ----------------\n" << endl;

    return 0;

}