
#include <iostream>
#include <cmath>

using namespace std;

const int row = 10;
const int collom = 10;

int papan [row][collom] = {};
int duid = 100;

void Game_Suit ();

/*

    Game suit mengandalkan attack dan defence
    Modal awal : attack = 100 defence = 100 dan HP 1000 
    Gacha atribut untuk mendapatkan atribut yang bagus, buat nambahin atk dan def
    Gacha atribut juga bisa berpeluang zonk (ada 4)
    Atribut gacha : atk = 100 + (5% - 75%), dan def = 100 + (2% - 73%)
    1 x Gacha = 50 LS
    modal duid = 100 LS
    Menang game suid + (2-25) LS

*/

int main () {

    cout << endl;

    Game_Suit ();

    cout << endl << endl;

    return 0;

}

void Gacha (int y, int x) {

    //Papan (baris, kolom) (y,x)

    for (int r = 0; r < collom; r++) {
        cout << "\t" << r;
       
        for (int c = 1; c < row; c++) {
            
            if (r < 1) {
                papan[r][c] = c;
            }
            else {
                papan[r][c] = 0;
            }
            papan[y][x] = 1;
            cout << " | " << papan[r][c];
        }

        cout << " | " << endl;
    }

}

void Kemampuan (int &atk, int &def) {

    atk = 100 + (100 * (atk/100));
    def = 100 + (100 * (def/100));

}

void Duid (int &uang, int tambah) {
    uang = uang + tambah;
}

double Nyerang (double atk_ku, double def_musuh) {

    double hasil = atk_ku - (def_musuh/100);
    return hasil;

}

void Game_Suit () {

    int sign_AI, nyawa_AI = 1000;
    int sign_user, nyawa_user = 1000;

    int atk_user = 100, def_user = 100;
    int atk_AI = 0, def_AI = 0;

    srand (time(0));

    atk_AI = 150 + rand () % 700;
    def_AI = 120 + rand () % 630;

    cout << "***** Game Suit *****\n" << endl;

    cout << "Semut = 1" << endl;
    cout << "Orang = 2" << endl;
    cout << "Gajah = 3" << endl;

    Kemampuan (atk_user, atk_AI);
    cout << "\nAttack mu  : " << atk_user << "\t|\tAttack AI  : " << atk_AI << endl;
    cout << "Defence mu : " << def_user << "\t|\tDefence AI : " << def_AI << endl;

    cout << endl;

    while (nyawa_user > 0 && nyawa_AI > 0) {

        cout << "Nyawa mu : " << nyawa_user << "\t|\tNyawa AI : " << nyawa_AI << endl;

        cout << "Masukan pilihan mu : ";
        cin >> sign_user;
        
        sign_AI = 1 + rand () % 3;

        if (sign_user != 1 && sign_user != 2 && sign_user != 3) {
            cout << "Error input" << endl;
        }

        else {

            cout << "\n" << sign_user << " lawan " << sign_AI << endl;

            if (sign_AI == 1 && sign_user == 1 || sign_AI == 2 && sign_user == 2 || sign_AI == 3 && sign_user == 3) {
                //Kalo seri
                cout << "Hasilnya seri" << endl << endl;
            }
            else if (sign_AI == 1 && sign_user == 3 || sign_AI == 2 && sign_user == 1 || sign_AI == 3 && sign_user == 2) {
                //Kalo kalah
                cout << "AI menyerang mu " << endl << endl;
                nyawa_user = nyawa_user - Nyerang (atk_AI, def_user);
            }
            else {
                //Kalo menang
                cout << "Kamu menyerang AI " << endl << endl;
                nyawa_AI = nyawa_AI - Nyerang (atk_user, def_AI);
            }

        }

    }

    if (nyawa_AI > 0) {
        cout << "\nKamu kalah" << endl;
    }
    else if (nyawa_user > 0){

        int tambah_duid = 2 + rand () % 25; 

        cout << "Kamu menang" << endl;
        Duid (duid, tambah_duid);
        cout << "Kamu dapat " << tambah_duid << " LS" << endl;
    }

}

    /*
        int papan [row][collom] = {};

    int panjang, lebar;

    cout << "Masukan ukuran papan" << endl;
    cout << " >> Panjang : ";
    cin >> panjang;
    cout << " >> Lebar : ";
    cin >> lebar;

    cout << endl;

    for (int r = 0; r < lebar; r++) {
        cout << "\t";

        for (int c = 0; c < panjang; c++) {
            cout << papan[r][c] << " ";
        }
        cout << endl;
    }

    cout << endl;

    */