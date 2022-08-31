
#include <iostream>
#include <string>

using namespace std;

void jumlah (int& n) {

    double hasil = 0;
    double angka[n];
    
    cout << "Masukan angka nya : " << endl;

    for (int s = 0; s < n; s++) {
        cin >> angka[s];
    }

    for (int i = 0; i < n; i++) {
        hasil = angka[i] + hasil;
    }

    cout << "Hasilnya adalah " << hasil << endl;

}

void kali (int& n) {

    double hasil = 1;
    double angka[n];

    cout << "\nMasukan angka nya : \n" << endl;

    for (int s = 0; s < n; s++) {
        cin >> angka[s];
    }

    for (int s = 0; s < n; s++) {
        hasil = hasil * angka[s];
    }

    cout << "\nHasilnya adalah " << hasil << endl;

}

void kurang (int& n) {

    double hasil = 0;
    double angka[n];

    cout << "\nMasukan angkanya : \n" << endl;

    for (int s = 0; s < n; s++) {
        cin >> angka[s];
    }

    for (int s = 0; s < n; s++) {
        
        if (s <= 0) {
            hasil = abs (hasil - angka[s]);
        }
        else {
            hasil = hasil - angka[s];
        }

    }

    cout << "\nHasilnya adalah " << hasil << endl;

}

void bagi (int& n) {

    double hasil = 1;
    double angka[n];

    cout << "Masukan angkanya : \n" << endl;

    for (int s = 0; s < n; s++) {
        cin >> angka[s];
    }

    for (int s = 0; s < n; s++) {
        
        if (s <= 0) {
            hasil = (hasil / angka[s]) * (angka[s]*angka[s]);
        }
        else {
            hasil = hasil / angka[s];
        } 
    }

    cout << "\nHasilnya adalah " << hasil << endl;

}

int main () {

    cout << "\tKalkulator Sederhana\n" << endl;

    int banyak_data;
    char operator_aritmatika;

    cout << "Masukan operator aritmatika (*, +, /, -) : ";
    cin >> operator_aritmatika;

    cout << "Masukan berapa banyak data : ";
    cin >> banyak_data;

    switch (operator_aritmatika) {
    
        case '+' :
            jumlah (banyak_data);
            break;

        case '*' :
            kali (banyak_data);
            break;

        case '/' : 
            bagi (banyak_data);
            break;

        case '-' :
            kurang (banyak_data);
            break;

        default:
            break;
    
    }

    cout << endl;

    return 0;

}