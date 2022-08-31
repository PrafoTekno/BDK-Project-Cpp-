
#include <iostream>
using namespace std;

// Kalkulasi
double jam (double);
double menit (double);
double detik (double);

// Tampilan
void Waktu (double);
void Selisih (double, double);

int main () {

    cout << "Membaca waktu\n" << endl;

    double waktu1, waktu2;

    cout << "Masukan waktu 1 dalam jam : ";
    cin >> waktu1;

    cout << "\n------------------------------------\n" << endl;

    Waktu (waktu1);
    cout << endl;

    cout << "Masukan waktu 2 dalam jam : ";
    cin >> waktu2;

    cout << "\n------------------------------------\n" << endl;

    Waktu (waktu2);
    cout << "\n------------------------------------\n" << endl;

    Selisih (waktu1, waktu2);

    cout << endl;

    return 0;

}

//Fungsi penjabaran

double jam (double t) {
    return t;
}

double menit (double t) {
    return t * 60;
}

double detik (double t) {
    return t * 3600;
}

void Waktu (double t) {

    cout << t << " jam = " << jam (t) << " jam" << endl;
    cout << t << " jam = " << menit (t) << " menit" << endl;
    cout << t << " jam = " << detik (t) << " detik" << endl; 

}

void Selisih (double t1, double t2) {

    if (t1 > t2) {

        cout << "Selisih jam = " << jam (t1) - jam (t2) << " jam" << endl;
        cout << "Selisih menit = " << menit (t1) - menit (t2) << " menit" << endl;
        cout << "Selisih detik = " << detik (t1) - detik (t2) << " detik" << endl;

    } 
    else {

        cout << "Selisih jam = " << jam (t2) - jam (t1) << " jam" << endl;
        cout << "Selisih menit = " << menit (t2) - menit (t1) << " menit" << endl;
        cout << "Selisih detik = " << detik (t2) - detik (t1) << " detik" << endl;

    }

}