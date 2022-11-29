
#include <iostream>
#include <string>

using namespace std;

// Global Variable

const int row = 500;
const int collom = 500;

double nilai_quis [row][collom] = {};
string matkul [row] = {""};

void rata_rata (int, int, char);

int main () {

    cout << "\n\t======== Mengolah Nilai Quis ========\n\n" << endl; 

    // Scope Variable

    int banyak_matkul, banyak_quis;
    char pilihan;

    cout << " ^ Berapa matkul yang hendak dilihat      : ";
    cin >> banyak_matkul;
    cout << " ^ Berapa banyak quis yang hendak dilihat : ";
    cin >> banyak_quis;

    cout << endl;

    cout << "\n--------------------------------------" << endl;

    cout << "Mau sorting nilai berdasarkan apa : " << endl;
    cout << "m = matkul" << endl;
    cout << "q = quis " << endl;
    cout << "Masukan jawaban mu : ";
    cin >> pilihan;

    cout << "\nMasukan matkulnya : " << endl;

    for (int i = 0; i < banyak_matkul; i++) {
        cout << ">> ";
        cin >> matkul[i];
    }
    
    cout << "----------------------------------------\n" << endl;

    rata_rata (banyak_matkul, banyak_quis, pilihan);

    cout << endl;

    return 0;

}

void rata_rata (int a, int b, char pilihan) {

    double jumlah_data;
    double hasil[row];
    double nilai[row][collom];

    if (pilihan == 'm' || pilihan == 'M') {

        // Input nilai + menghitung rata-rata

        for (int r = 0; r < a; r++) {

            cout << "\nMasukan nilai " << matkul[r] << endl;
            jumlah_data = 0;

            for (int c = 0; c < b; c++) {

                cout << " * Quis " << c+1 << " : ";
                cin >> nilai[r][c];
                jumlah_data = jumlah_data + nilai[r][c];    
           
            }

            hasil[r] = jumlah_data/b; 
            cout << endl;

        }

        cout << "\n==============================================" << endl;

        // Menampilkan rata-rata

        for (int r = 0; r < a; r++) {

            cout << "Rata - rata " << matkul[r] << " : ";
            cout << hasil[r] << endl;

            cout << endl;

        }

        cout << "==============================================" << endl;

    }

    else if (pilihan == 'q' || pilihan == 'Q') {

        // Input nilai + menghitung rata-rata

        for (int r = 0; r < b; r++) {

            cout << "\nMasukan nilai quis " << r+1 << endl;

            jumlah_data = 0;

            for (int c = 0; c < a; c++) {

                cout << " * " << matkul[c] << " : ";
                cin >> nilai[r][c];
                jumlah_data = jumlah_data + nilai[r][c];    
           
            }

            hasil[r] = jumlah_data/a; 
            cout << endl;

        }

        cout << "\n==============================================" << endl;

        // Menampilkan rata-rata

        for (int r = 0; r < b; r++) {

            cout << "Rata - rata quis " << r+1 << " : ";
            cout << hasil[r] << endl;

            cout << endl;

        }

        cout << "==============================================" << endl;

    }

    else {
        cout << "Error message 303 : Input tidak sesuai" << endl;
    }


}


