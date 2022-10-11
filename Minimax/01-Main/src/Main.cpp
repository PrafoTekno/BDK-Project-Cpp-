
#include <iostream>
using namespace std;

int minimax (int nilai[], int depth, int index, int h, bool cekMax) {

    //nilai[] = adalah kumpulan nilai yang akan di cek
    //depth = kedalaman dari pengecekan
    //index = menyatakan index saat ini
    //h = batas untuk si depth (berapa kali proses pengecekan)
    //cekMax = untuk mengetahui saat ini maximizing player atau minimizing player

    // Hasil akhir

    if (depth == h) {
        return nilai[index]; //menampilkan nilai dipermukaan
    }  

    // Pengecekan

    if (cekMax) {

        int eval1 = minimax (nilai, depth+1, index*2, h, false);
        int eval2 = minimax (nilai, depth+1, index*2+1, h, false);
       
        return max (eval1, eval2);
    
    }

    else {

        int eval1 = minimax (nilai, depth+1, index*2, h, true);
        int eval2 = minimax (nilai, depth+1, index*2+1, h, true);
       
        return min (eval1, eval2);

    } 

}

int kedalam (int n) {
    return (n == 0) ? 0 : 1 + kedalam (n/2); 
}

int main () {

    cout << "\n\t========== MINIMAX ==========\n" << endl;

    int bilangan [] = {3,5,6,7,9,10,4,22};
    int ukuran = sizeof (bilangan) / sizeof (bilangan[0]);
    int h = kedalam (ukuran);

    cout << "Cek nilai h : " << h << endl;

    int hasil = minimax (bilangan, 0, 0, h, true);

    cout << "Bilangan-bilangannya : ";

    for (int i = 0; i < ukuran; i ++) {
        cout << bilangan[i] << ", ";
    }

    cout << "\nHasilnya adalah : " << hasil << endl;

    cout << endl;

    return 0;

}