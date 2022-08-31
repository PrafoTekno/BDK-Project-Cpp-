
#include <iostream>
using namespace std;

int main () {

    cout << "Mengurutkan bilangan\n" << endl;

    int a, b, c;

    cout << "Masukan bilangan bulat pertama : ";
    cin >> a;
    cout << "Masukan bilangan bulat kedua   : ";
    cin >> b;
    cout << "Masukan bilangan bulat ketiga  : ";
    cin >> c;

    cout << endl;

    if (a > b && b > c) {
        cout << "Urutannya : " << c << ", " << b << ", " << a << endl;
    }
    else if (c > a && a > b) {
        cout << "Urutannya : " << b << ", " << a << ", " << c << endl;
    } 
    else if (b > c && c > a) {
        cout << "Urutannya : " << a << ", " << c << ", " << b << endl; 
    }

    cout << endl;

    return 0;

}