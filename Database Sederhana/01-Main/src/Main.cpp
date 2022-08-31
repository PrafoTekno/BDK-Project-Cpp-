
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Shinobi {

    public :

        string nama;
        string kode;
        string kelas;
        char rank;

        string Tampil () {

            return "Nama  : " + this->nama + "\n" + "Kode  : " + this->kode + "\n" + 
                   "Kelas : " + this->kelas + "\n" + "Rank  : " + this->rank + "\n" +
                   "------------------------\n";

        }

};

class DataBase {

    public : 

        ofstream out;
        ifstream in;
        string nama_file;

        DataBase () {
          this->nama_file = "Data Shinobi";
        }

        void SaveData (Shinobi ninja) {
        
            DataBase::out.open (DataBase::nama_file, ios::app);
            DataBase::out << ninja.Tampil ();
            DataBase::out.close ();
        
        }

        void ShowData () {
            
            this->in.open (DataBase::nama_file, ios::in);
            string text;

            while (!DataBase::in.eof()) {

                getline (this->in, text);
                cout << text << endl;
            
            }
        
        }

};

void Tampilkan (Shinobi&, DataBase&);

int main () {

    cout << "\n\tData Shinobi" << endl;
    cout << "=============================\n" << endl;

    Shinobi anggota = Shinobi ();
    DataBase kumpulan_data = DataBase ();

    Tampilkan (anggota, kumpulan_data);
    
    return 0;

}

void Tampilkan (Shinobi &ninja, DataBase &data) {

    string nama, kode, kelas;
    char rank; 

    cout << "Masukan nama\t : ";
    getline (cin, nama);
    cout << "Masukan kode\t : ";
    getline (cin, kode);
    cout << "Masukan kelas\t : ";
    getline (cin, kelas);
    cout << "Masukan rank\t : ";
    cin >> rank;

    ninja.nama = nama;
    ninja.kode = kode;
    ninja.kelas = kelas;
    ninja.rank = rank;

    cout << "\n\n--- Data Output ---\n" << endl;

    data.SaveData (ninja);
    data.ShowData ();

}

