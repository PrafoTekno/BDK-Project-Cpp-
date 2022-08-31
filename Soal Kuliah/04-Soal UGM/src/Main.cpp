
#include <iostream>
using namespace std;

int main () {

    cout << "Menukar 2 nilai\n" << endl;

    int a, b;

    cout << "Masukan nilai a : ";
    cin >> a;
    cout << "Masukan nilai b : ";
    cin >> b;

    cout << "\n------ Penukaran nilai ------\n" << endl;

    int selisih = a - b;

    if (selisih >= 0) {
        a = b;
        b += selisih;
    } else {
        b = a;
        a -= selisih;
    }

    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;

    cout << endl;

    return 0;

}