
#include <iostream>
using namespace std;

double jam (double t) {
    return t / 3600;
}

double menit (double t) {
    return t / 60;
}

double detik (double t) {
    return t;
}

int main () {

    cout << "Membaca waktu\n" << endl;

    double input_waktu;

    cout << "Masukan waktu dalam detik : ";
    cin >> input_waktu;
    
    cout << endl;

    cout << input_waktu << " detik = " << jam (input_waktu) << " jam" << endl;
    cout << input_waktu << " detik = " << menit (input_waktu) << " menit" << endl;
    cout << input_waktu << " detik = " << detik (input_waktu) << " detik\n" << endl;

    return 0;

}