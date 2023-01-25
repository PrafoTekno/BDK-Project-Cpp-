
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Akun {

    public :

        string ID_akun;
        string PIN_akun;
        string tittle;

        string nama_karakter;

        string duid;
        string menang;

        Akun (string ID, string PIN) {
            this->ID_akun = ID;
            this->PIN_akun = PIN;
        }

        string Tampil () {   //Yang akan tampil di database

            return "ID : " + this->ID_akun + "\t PIN : " + this->PIN_akun +
                   "\nNama : " + this->nama_karakter + "\nTittle  : " + this->tittle + 
                   "\nMenang : " + this->menang + "\nDuid : " + this->duid +
                   "\n------------------------\\\n";

        }

};

class Database {

    private :

        ifstream in;
        ofstream out;
        string nama_file;

    public :

        Database () {
            Database::nama_file = "Data_Pemain";
        }

        void save (Akun orang) {

            Database::out.open (Database::nama_file, ios::app);
            Database::out << orang.Tampil ();
            Database::out.close ();

        }

        void load (Akun orang, string ID, string PIN) {

            Database::in.open (Database::nama_file, ios::in);
            string kalimat;

            if (ID == orang.ID_akun && PIN == orang.PIN_akun) {

                while (Database::in.eof ()) {

                    getline (this->in, kalimat);

                   // if (kalimat != ID && kalimat != PIN && kalimat == "\\\n") {
                     //   cout << "Tes" << endl;
                       // break;
                   // }
                    //else {
                        cout << kalimat << endl;
                    //} 

                }

            } else {
                cout << "ID atau PIN salah" << endl;
            }

        }


};

void login (Akun&, Database&);
void sign_up (Akun&, Database&);

string ID, PIN;

int main () {

    cout << "\n\t========= Skenario Save-an Game =========\n" << endl;

    char status_akun, lanjut;

    Akun user = Akun (ID, PIN);
    Database data = Database ();

    while (true) {

        cout << "Sudah punya akun? (y/n) : ";
        cin >> status_akun;

        if (status_akun == 'y') {
            login (user, data);
        }
        else if (status_akun == 'n') {
            sign_up (user, data);
        }
        else {
            cout << "Error 104 : Input tidak sesuai" << endl;
        }

        cout << "\nLanjutkan proses? (y/n) : ";
        cin >> lanjut;

        if (lanjut == 'n') {
            break;
        }

        cout << endl;

    }

    cout << "\nTerima kasih\n" << endl;

    return 0;

}

void login (Akun& people, Database& data) {

    cout << "\nMasukan ID mu : ";
    cin >> ID;
    cout << "Masukan PIN mu : ";
    cin >> PIN;

    data.load (people, ID, PIN);

}

void sign_up (Akun& people, Database& data) {

    cout << "\nBuat ID mu : ";
    cin >> ID;
    cout << "Buat PIN mu : ";
    cin >> PIN;

    people.ID_akun = ID;
    people.PIN_akun = PIN;

    cout << "\nMasukan nama karakter mu : ";
    cin >> people.nama_karakter;
    cout << "Masukan tittle mu : ";
    cin >> people.tittle;
    cout << "Masukan berapa kali menang : ";
    cin >> people.menang;
    cout << "Masukan besar duid mu : ";
    cin >> people.duid;

    data.save (people);
    cout << "\nAkun sudah di buat" << endl;

}