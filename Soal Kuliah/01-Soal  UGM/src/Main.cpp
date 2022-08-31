
#include <iostream>
using namespace std;

double detik (double t) {
    return t;
}

double menit (double t) {
    return t / 60;
}

double jam (double t) {
    return t /  3600;
}

int main () {

    cout << "Program baca waktu\n" << endl;

    double input_waktu; 
    char status;

    cout << "Masukan satuan waktu (a = detik, b = menit, c = jam) : ";
    cin >> status;
    cout << "Masukan nilai waktu : ";
    cin >> input_waktu;

    cout << endl;

    switch (status) {
        
        case 'a' : 
        cout << input_waktu << " detik = " << detik (input_waktu) << " detik" << endl;
        break;

        case 'b' :
        cout << input_waktu << " detik = " << menit (input_waktu) << " menit" << endl;
        break;

        case 'c' :
        cout << input_waktu << " detik = " << jam (input_waktu) << " jam" << endl;
        break;

    }

    cout << "\nSampai jumpa\n" << endl;

    return 0;

}
