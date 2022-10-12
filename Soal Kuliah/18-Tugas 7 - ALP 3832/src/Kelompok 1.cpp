
#include <iostream>

using namespace std;

int main () {

    cout << "\n\t======= Mari Membuat Segitiga =======\n\n" << endl;
    
    //Variable untuk buat segitiga
    char tipe;
    double tinggi_segitiga = 0;

    //Variable untuk loopingan while
    int status = 0;

    //Pemilihan Tipe (gerbang)
    cout << "\tTipe Segitiga" << endl; 
    cout << "----------------------------------\n" << endl;
    
    cout << "a : segitiga sama sisi tegak" << endl;
    cout << "b : segitiga sama sisi terbalik" << endl;
    cout << "\n---------------------------------" << endl;

    while (status < 1) {

        cout << "\nMasukan pilihan mu : ";
        cin >> tipe;

        if (tipe == 'a' || tipe == 'A') {

            cout << "\n---------------------------------\n" << endl;

            cout << "Masukan tinggi segitiga mu : ";
            cin >> tinggi_segitiga;

            cout << endl;

            cout << "Ini dia segitiga mu\n" << endl;

            for (int t = 0; t < tinggi_segitiga; t++) {

                for (int space = tinggi_segitiga; space > t; space--) {
                    cout << " ";
                }
                for (int i = 0; i <= t; i++) {
                    cout << "* ";
                }
        
                cout << endl;
            }

            status += 1;

        }

        else if (tipe == 'b' || tipe == 'B') {
            
            cout << "\n---------------------------------\n" << endl;

            cout << "Masukan tinggi segitiga mu : ";
            cin >> tinggi_segitiga;

            cout << endl;

            cout << "Ini dia segitiga mu\n" << endl;

            for (int t = 0; t < tinggi_segitiga; t++) {
            
                for (int space = 0; space < t; space++) {
                    cout << " ";
                }
                for (int i = tinggi_segitiga; i > t; i--) {
                    cout << "* ";
                }

                cout << endl;

            }

            status += 1;

        }

        else {
            cout << "Error Code 221 : Input tidak sesuai\n" << endl;
        }

    }

    cout << endl;

    cout << "Luas segitiganya adalah : " << (tinggi_segitiga * tinggi_segitiga)/2 << " satuan^2" << endl;
    cout << "Keliling segitiganya adalah : " << tinggi_segitiga * 3 << " satuan" << endl;

    cout << endl;

    return 0;

}