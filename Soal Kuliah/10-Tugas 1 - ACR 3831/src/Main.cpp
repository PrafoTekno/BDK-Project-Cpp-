
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class User {

    public :

        string nama_depan;
        int tahun_lahir;
        int umur;

        User (string nama = "", int tahun_lahir = 0) {
        
            User::nama_depan = nama;
            User::tahun_lahir = tahun_lahir;
            User::umur = 2022 - User::tahun_lahir;
        
        }

        string User_baru () {
            return nama_depan + to_string (tahun_lahir) + "@PraVak.fo.id\n";
        }

        string Data_User () {
           
            if (this->umur < 12) {

                return "Nama user     : " + User::nama_depan + "\n" + 
                       "Umur user     : " + to_string (umur) + "\n" +
                       "Jadwal vaksin : " + "13 September 2022" + 
                       "\n**************************************\n\n"; 
            
            }

            else if (this->umur >= 12 && this->umur <= 45) {

                return "Nama user     : " + User::nama_depan + "\n" + 
                       "Umur user     : " + to_string (umur) + "\n" +
                       "Jadwal vaksin : " + "12 September 2022" + 
                       "\n**************************************\n\n"; 
            
            }

            else {

                return "Nama user     : " + User::nama_depan + "\n" + 
                       "Umur user     : " + to_string (umur) + "\n" +
                       "Jadwal vaksin : " + "11 September 2022" + 
                       "\n**************************************\n\n";

            }

        }

};

class Database {

    public :

        string nama_file;
        ofstream out;
        ifstream in;

    public :

        Database (const char* nama_file = "file.txt") {
            Database::nama_file = nama_file;
        }

        void save_akun (User orang) {

            // Menulis kan data ke dalam database

            this->out.open (Database::nama_file, ios::app);
            this->out << orang.User_baru ();
            this->out.close ();

        } 

        void save_data (User orang) {

            this->out.open (Database::nama_file, ios::app);
            this->out << orang.Data_User ();
            this->out.close ();

        }

        void load (User orang) {
            
            // Membaca database

            this->in.open (Database::nama_file, ios::in);
            string text; // menampung data di dalam file.txt

            while (!this->in.eof ()) { //menampilkan semua data di file.txt
            
                getline (this->in, text);
                cout << text << endl;
            
            }

        }

};

User akun_orang = User ();
Database akun = Database ();

string nama_depan;
int tahun_lahir;

void Buat_Akun () {

    cout << "\nMasukan nama depan anda  : ";
    cin >> nama_depan;
    cout << "Masukan tahun lahir anda : ";
    cin >> tahun_lahir;

    akun_orang.nama_depan = nama_depan;
    akun_orang.tahun_lahir = tahun_lahir;
    akun.nama_file = "Akun.txt";

    akun.save_akun (akun_orang);

    cout << "\nID PraVak : " << nama_depan << tahun_lahir << "@PraVak.fo.id" << endl;
    cout << "\nSelamat akun PraVak anda sudah jadi" << endl;

}

void Data_Vaksinasi () {
    
    char status_vaksin;

    User data_orang = User (nama_depan, tahun_lahir);
    Database data = Database ("Data.txt"); 

    cout << "\nApakah anda sudah vaksin? (y/n) : ";
    cin >> status_vaksin;

    if (status_vaksin == 'y') {
        cout << "\nMaaf anda tidak dapat ikut vaksinasi, karena anda sudah vaksin\n" << endl;
    }
    else if (status_vaksin == 'n') {
       
        if (data_orang.umur < 12) {
            cout << "\nSilahkan datang pada 13 September 2022 untuk vaksinasi" << endl;
        }
        else if (data_orang.umur >= 12 && data_orang.umur <= 45) {
            cout << "\nSilahkan datang pada 12 September 2022 untuk vaksinasi" << endl;
        }
        else {
            cout << "\nSilahkan datang pada 11 September 2022 untuk vaksinasi" << endl;
        }

        data.save_data (data_orang);

    }

    else {
        cout << "Error : Input tidak ada " << endl;
    }

}

void Daftar_Vaksinasi () {

    string ID_PraVak;
    string text;
    ifstream myFile;

    int val; //Buat indikator ada atau tidaknya akun

    cout << "Masukan ID anda : ";
    cin >> ID_PraVak;

    myFile.open ("Akun.txt", ios::in); //Buat buka file akun yang telah dibuat

    while (!myFile.eof ()) { //Mengecek ada atau tidak ID yang dimasukan
        
       getline (myFile, text);  

       if (ID_PraVak == text) {
         val = 1;
         break;
       }
    
    }

    if (val == 1) {
        cout << "ID : " << ID_PraVak << " sudah ada" << endl << endl;         
        Data_Vaksinasi ();
    }
    else {
        cout << "Akun PraVak belum ada, silahkan buat akun PraVak terlebih dahulu\n" << endl;
    }

}

void List_Vaksinasi () {

    User *data_orang = new User (nama_depan, tahun_lahir);
    Database *data = new Database ("Data.txt");

    data->load (*data_orang);

}

bool a = false;

void Home () {

    int window;
    char status_akun;

    cout << "--------------------------------------" << endl;
    cout << "\n1 -> Buat akun PraVak ID" << endl;
    cout << "2 -> Daftar vaksinasi ID" << endl;
    cout << "3 -> Lihat list pendaftaran vaksinasi" << endl;
    cout << "4 -> Keluar" << endl;

    cout << "\nPilih menu : ";
    cin >> window;

    cout << "--------------------------------------\n" << endl;

    switch (window) {

        case 1 :
        Buat_Akun ();
        break;

        case 2 : 
        Daftar_Vaksinasi ();
        break;

        case 3 :
        List_Vaksinasi ();
        break;

        default :
        a = true;
        break;

    }

}

int main () {

    cout << "\t===== Vaksinasi ID =====\n\n" << endl;

    while (a == false) {
        Home ();
    }

    cout << "\nTerima kasih, sampai jumpa\n" << endl;

    return 0;

}