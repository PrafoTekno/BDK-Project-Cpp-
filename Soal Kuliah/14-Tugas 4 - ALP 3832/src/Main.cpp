
#include <iostream>

using namespace std;

int main () {

    cout << "\t===== Menebak Angka =====\n\n" << endl;

    //Variable yang dibutuhkan 

    int angka_input, angka_tebakan = 13;
    int putaran_ke = 0, clue;

    //Looping sebanyak 3 kali

    while (putaran_ke < 3) {

        cout << "Masukan sebuah bilangan bulat : ";
        cin >> angka_input;

        putaran_ke ++;
        clue = angka_tebakan - angka_input; //clue = selisih angka tebakan dengan angka input

        //Mengatur kondisi-kondisi yang kemungkinan terjadi

        if (angka_input == angka_tebakan) {
            cout << "\nWah tebakan kamu benar\n" << endl;
            break;
        }
        else if (putaran_ke == 2) {
            cout << "\nAngkanya itu adalah " << clue << " dari jawaban kamu\n" << endl; 
        }
        else if (putaran_ke == 3) {
            cout << "\nKamu gagal dalam menebak angkanya\n" << endl;
        }
        else {
            cout << "" << angka_input << " bukanlah angka yang dimaksud\n" << endl;
        }

    }

    cout << endl;

    return 0;

}
