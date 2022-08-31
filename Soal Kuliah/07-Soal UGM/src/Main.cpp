
#include <iostream>
using namespace std;

int lembur (int t) {
    return (t / 50) * 1000;
}
int total_gaji (int a, int b) {
    return a + b;
}

int main () {

    cout << "Menghitung Pendapatan\n" << endl;

    int gaji_pokok, jam_lembur;

    cout << "\n\n======== Golongan 1 ========\n" << endl;

    gaji_pokok = 1000000;
    jam_lembur = 10000;

    cout << "Gaji pokok = Rp " << gaji_pokok << endl; 
    cout << "Jam lembur = " << jam_lembur << " jam" << endl;
    cout << "Gaji lembur = Rp " << lembur (jam_lembur) << endl;

    cout << "\n----------------------------" << endl;
    cout << "Total gaji = Rp " << total_gaji (lembur (jam_lembur), gaji_pokok) << endl;

    cout << endl;

    cout << "\n\n======== Golongan 2 ========\n" << endl;

    gaji_pokok = 2000000;
    jam_lembur = 20000;

    cout << "Gaji pokok = Rp " << gaji_pokok << endl; 
    cout << "Jam lembur = " << jam_lembur << " jam" << endl;
    cout << "Gaji lembur = Rp " << lembur (jam_lembur) << endl;

    cout << "\n----------------------------" << endl;
    cout << "Total gaji = Rp " << total_gaji (lembur (jam_lembur), gaji_pokok) << endl;
    
    cout << endl;

    cout << "\n\n======== Golongan 3 ========\n" << endl;

    gaji_pokok = 3000000;
    jam_lembur = 30000;

    cout << "Gaji pokok = Rp " << gaji_pokok << endl; 
    cout << "Jam lembur = " << jam_lembur << " jam" << endl;
    cout << "Gaji lembur = Rp " << lembur (jam_lembur) << endl;

    cout << "\n----------------------------" << endl;
    cout << "Total gaji = Rp " << total_gaji (lembur (jam_lembur), gaji_pokok) << endl;
    
    cout << endl;

    return 0;

}