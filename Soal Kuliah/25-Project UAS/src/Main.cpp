
#include <iostream>
#include <string>

using namespace std;

// Atribut Variable

int duid = 200;
int attack = 100, deffence = 100;

string title = "Bronze";
string nama_karakter;

char bentuk_karakter, menu_game;

void Game_Suit ();

void Karakter (int, int);

// Hal lain
void Kemampuan (int &, int &, int, int);
void Duid (int &, int);

void Profil ();
void Gacha (int, int);

/* Deskripsi Game

    Game suit mengandalkan attack dan defence
    Modal awal : attack = 100 defence = 100 dan HP 1000 
    Gacha atribut untuk mendapatkan atribut yang bagus, buat nambahin atk dan def
    Gacha atribut juga bisa berpeluang zonk (ada 4)
    Atribut gacha : atk = 100 + (5% - 75%), dan def = 100 + (2% - 73%)
    1 x Gacha = 50 LS
    modal duid = 100 LS
    Menang game suid + (2-25) LS

*/

int main () {

    cout << endl;

    cout << "\t=-=-=-=-= YouVon =-=-=-=-=\n" << endl;

    srand (time (0));

    cout << "Masukan nama karakter mu : ";
    getline (cin, nama_karakter);

    cout << "\n--->> Karakter <<---" << endl;
    cout << "   a = segitiga" << endl;
    cout << "   b = ketupat" << endl;
    cout << "   c = kotak" << endl;
    cout << "   d = Trapesium" << endl;
    cout << "----------------------" << endl;
    cout << "Pilih karakter mu : ";
    cin >> bentuk_karakter;

    Profil ();

    while (true) {

        cout << "-----&& Menu Game &&-----\n" << endl;
        cout << "   @ = Profil" << endl;
        cout << "   # = Tempur" << endl;
        cout << "   $ = Gacha" << endl;
        cout << "   % = Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Pilih menu : ";
        cin >> menu_game;

        cout << endl;

        if (menu_game == '@') {
            Profil ();
        }
        else if (menu_game == '#') {
            Game_Suit ();
        }
        else if (menu_game == '$') {
            
            cout << "\n     ^^^^^^^^^^^^^^^^^^^ Gacha ^^^^^^^^^^^^^^^^^^^" << endl;
            cout << "\n1 kali gacha seharga 50 LS " << endl;

            if (duid >= 50) {

                int x_kotak, y_kotak;

                Gacha (0,1);
                cin >> x_kotak >> y_kotak;

                if (x_kotak > 9 || y_kotak > 9) {
                    cout << "Pesan error : koordinat tidak ditemukan" << endl << endl;
                }
                else if (x_kotak == 1 && y_kotak == 0 || x_kotak == 0 && y_kotak == 1) {
                    cout << "Pesan error : salah pilih" << endl << endl;
                }
                else {
                    Duid (duid, -50);
                    Gacha (x_kotak, y_kotak);
                }

            }

            else {
                cout << "Kamu butuh " << 50-duid << " LS untuk melakukan gacha\n" << endl;
            }
        
        }

        else if (menu_game == '%') {
            break;
        }
        else {
            cout << "Pesan error : Input yang dimasukan tidak sesuai \\~.~/ " << endl;
        }

    }

    cout << "Terima kasih telah bermain, " << nama_karakter << " sampai jumpa kembali \\^.^/" << endl;
    cout << endl << endl;

    return 0;

}

// Variable Gacha

const int row = 10;
const int collom = 10;

int papan [row][collom] = {};
int atribut;

    // Nama Senjata

    string senjata [40] = 
    {"Indra Sword", "Rama Bow", "Bima Axe", "Fang Blade", "Dual Knife", "Keris", "Arabian Sword", "Karambit", "Kunai", "Shiruken"
    ,"Aquilla Favonia", "Fredom Sworn", "Haran Geppaku Futsu", "Mistplitter Reforged", "Primordial Jade Cutter","Skyward Blade", "Summit Shaper", "Amemona Kageuchi", 
    "Blackliff Longsword", "Cinnabar Spindle","Favonius Sword", "Festering Desire", "Iron Sting", "Kagotsurube Isshin", "Lion's Roar","Prototype Rancour", "Royal Longsword",
     "Sacrificial Sword", "Sapwood Blade","Alley Flash", "Black Sword", "Flute", "Toukabou Shigure", "Xhiphos Moonlight","Cool Steel", "Dark Iron Sword", 
     "Fillet Blade", "Skyrider Sword", "Fillet Blade", "Escalibur Sword"};

    string armor [40] = 
    {"Deadric Shield", "Aegis Shield", "Scorpion Shield", "Ballistic Shield", "Bubble Shield", "Boom Shield", "Hylian Shield", "Guardian Shield", "Valkrie Shield", "Dokkenshieldr"
    ,"Hatamoto Armor", "Imbricated Armor", "Ghost Armor", "Wolven Armor", "Varia Suit","Toussaint Armor", "Ilvadi Armor", "Shield Waver", "Smough Set", "Darnchen Armor","Alpha Armor", "Terminus Armor", "Ghama Armor", 
    "Cainhurst Set", "Scorpion Suit","ARS Suit", "HEV Suit", "Phazon Suit", "Mjolnir", "Helghast","Octo Camo", "Recon Armor", "Flaming Armor", "Madness Armor", "Hair","Combat Suit", "Warlock Suit", "Ranger Armor", 
    "Abyssal Armor", "Soulcalibur"};

    // Indexing senjata dan armor

    int val_senjata [35] = {};
    int val_armor [35] = {};
    int kode[10] = {};

    int pilih_pack = 1; // Pengambilan pack
    int menang = 0; // Berapa kali sudah menang

// Sistem Gacha

void Gacha (int y, int x) {

    //Papan (baris, kolom) (y,x)

    cout << endl;

    for (int r = 0; r < collom; r++) {
        cout << "\t" << r;
       
        for (int c = 1; c < row; c++) {
            if (r < 1) {
                papan[r][c] = c;
            }
            else {
                papan[r][c] = 0;
            }
            papan[y][x] = 1;
            cout << " | " << papan[r][c];
        }

        cout << " | " << endl;
    }

    cout << endl;

    int x_zonk, y_zonk; // Zonk ada di kotak random

    x_zonk = 1 + (rand () % 9);
    y_zonk = 1 + (rand () % 9);
    
    x_zonk = 2;
    y_zonk = 2;

    if (y == y_zonk && x == x_zonk) {

        cout << "Kotak (" << y << ", " << x << ")" << endl << endl;

        val_senjata[pilih_pack-1] = -30 + (rand () % -10);
        val_armor[pilih_pack-1] = -30 + (rand () % -10);

        cout << "KAMU DAPAT ZONK HAHAHAHA" << endl << endl;
        cout << "Attack : " << val_senjata[pilih_pack-1] << endl;
        cout << "Deffence : " << val_armor[pilih_pack-1] << endl << endl;

    }

    else if (y == 0 && x == 1 || y == 1 && x == 0) {
        cout << "Pilih koordinat kotak (y, x) : ";
    }

    else {

        cout << "Kotak (" << y << ", " << x << ")" << endl << endl;

        for (int i = 0; i < 10; i++) {

            // Pemberian besarnya kekuatan setiap senjata dan armor

            val_senjata[i] = 15 + (rand () % 440);
            val_armor[i] = 12 + (rand () % 410);

        }

        for (int i = 0; i < 10; i++) {

            // Pengurutan value senjata dan armor

            for (int j = i+1; j < 10; j++) {

                int tampung;

                if (val_senjata[i] > val_senjata[j]) {
                    
                    tampung = val_senjata[i];
                    val_senjata[i] = val_senjata[j];
                    val_senjata[j] = val_senjata[i];    
                
                }
                if (val_armor[i] > val_armor[j]) {
                
                    tampung = val_armor[i];
                    val_armor[i] = val_armor[j];
                    val_armor[j] = val_armor[i];
                
                }
            }

        }

        int batas;

        // Banyaknya penawaran pack berdasarkan sisa duid

        if (duid - 10 < 0) { 
            batas = duid;
        }
        else {
            batas = 10;
        }

        for (int i = 0; i < batas; i++) {

            // Pengambilan random senjata dan armor untuk 1 kali gacha

            kode[i] = 0 + (rand () % 40);

            cout << "Harga : " << i+1 << " LS" << endl;
            cout << senjata[kode[i]] << " : +" << val_senjata[i] << " attack" << endl;
            cout << armor[kode[i]] << " : +" << val_armor[i] << " deffence\n" << endl;

        }

        cout << "Pilih pack yang mana (dalam LS) : ";
        cin >> pilih_pack;

        Duid (duid, -pilih_pack);

        cout << "\n----- Selamat Kamu Dapat -----" << endl;
        cout << senjata[kode[pilih_pack-1]] << " : +" << val_senjata[pilih_pack-1] << " attack" << endl;
        cout << armor[kode[pilih_pack-1]] << " : +" << val_armor[pilih_pack-1] << " deffence" << endl;
        cout << "--------------------------------\n\n" << endl;

        atribut = 1;

    }

    Kemampuan (attack, deffence, val_senjata[pilih_pack-1], val_armor[pilih_pack-1]);

}

// Profil user

void Profil () {

    cout << "\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^" << endl << endl;

    // Tittle List 

    if (menang > 3) {
        title = "Silver";
    }
    else if (menang > 7) {
        title = "Gold";
    }
    else if (menang > 15) {
        title = "Platinum";
    }
    else if (menang > 27) {
        title = "Glory";
    }

    Karakter (0, 1);

    if (atribut == 1) {

        cout << "\n+_+_+_+ Atribut yang dimiliki +_+_+_+\n" << endl;
        cout << senjata[kode[pilih_pack-1]] << " : +" << val_senjata[pilih_pack-1] << " attack" << endl;
        cout << armor[kode[pilih_pack-1]] << " : +" << val_armor[pilih_pack-1] << " deffence" << endl;

    }

    cout << "\n*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^" << endl << endl;

}

// Bentuk Karakter user dan AI

void Segitiga (int x, int status) {

    string spasi (x, ' ');

    if (status == 1) {

        for (int i = 0; i < 4; i++) {

            cout << spasi;
        
            for (int j = 4; j > i; j--) {
                cout << " ";
            }
            for (int j = 0; j < i; j++) {
                cout << "* ";
            }

            if (i < 1) {
                cout << " \t\t+ Duid : " << duid << " LS"; 
            }
            else if (i < 2) {
                cout << " \t\t+ Attack : " << attack;
            }
            else if (i < 3) {
                cout << " \t\t+ Deffence : " << deffence;
            }
            else {
                cout << "\t\t+ Title : " << title;
            }

            cout << endl;
        
        }    

    }

    else {

        for (int i = 0; i < 4; i++) {

            cout << spasi;
        
            for (int j = 4; j > i; j--) {
                cout << " ";
            }
            for (int j = 0; j < i; j++) {
                cout << "* ";
            }

            cout << endl;
        
        }    

    }

    
}

void Ketupat (int x, int status) {

    string spasi (x, ' ');

    if (status == 1) {

        for (int i = 0; i < 6; i++) {

            cout << spasi;

            if (i < 3) {
                for (int j = 6; j > i; j--) {
                    cout << " ";
                }
                for (int j = 0; j < i; j++) {
                    cout << "* ";
                }
            }
            else {
                for (int j = 0; j < i; j++) {
                    cout << " ";
                }
                for (int j = 6; j > i; j--) {
                    cout << "* ";
                }
            }

            if (i < 1) {
                cout << " \t\t+ Duid : " << duid << " LS"; 
            }
            else if (i < 2) {
                cout << " \t\t+ Attack : " << attack;
            }
            else if (i < 3) {
                cout << " \t\t+ Deffence : " << deffence;
            }
            else if (i < 4) {
                cout << "\t\t+ Title : " << title;
            }

            cout << endl;
        }

    }

    else {

        for (int i = 0; i < 6; i++) {

            cout << spasi;

            if (i < 3) {
                for (int j = 6; j > i; j--) {
                    cout << " ";
                }
                for (int j = 0; j < i; j++) {
                    cout << "* ";
                }
            }
            else {
                for (int j = 0; j < i; j++) {
                    cout << " ";
                }
                for (int j = 6; j > i; j--) {
                    cout << "* ";
                }
            }

            cout << endl;
        }

    }

}

void Kotak (int x, int status) {

    string spasi (x, ' ');

    if (status == 1) {

        for (int i = 0; i < 4; i++) {

            cout << spasi;

            for (int j = 0; j < 4; j++) {
                cout << " *";
            }

            if (i < 1) {
                cout << " \t\t+ Duid : " << duid << " LS"; 
            }
            else if (i < 2) {
                cout << " \t\t+ Attack : " << attack;
            }
            else if (i < 3) {
                cout << " \t\t+ Deffence : " << deffence;
            }
            else {
                cout << " \t\t+ Title : " << title;
            }

            cout << endl;
        }

    }

    else {

        for (int i = 0; i < 4; i++) {

            cout << spasi;

            for (int j = 0; j < 4; j++) {
                cout << " *";
            }

            cout << endl;
        }

    }

}

void Trapesium (int x, int status) {

    string spasi (x, ' ');

    if (status == 1) {

        for (int i = 0; i < 4; i++) {

            cout << spasi;

            for (int j = 4; j > i; j--) {
                cout << " ";
            }
            for (int j = 0; j < i+4; j++) {
                cout << "* ";
            }

            if (i < 1) {
                cout << "\t+ Duid : " << duid << " LS"; 
            }
            else if (i < 2) {
                cout << "\t+ Attack : " << attack;
            }
            else if (i < 3) {
                cout << "\t+ Deffence : " << deffence;
            }
            else {
                cout << "\t+ Title : " << title;
            }

            cout << endl;

        }

    }

    else {

        for (int i = 0; i < 4; i++) {

            cout << spasi;

            for (int j = 4; j > i; j--) {
                cout << " ";
            }
            for (int j = 0; j < i+4; j++) {
                cout << "* ";
            }

            cout << endl;
    
        }

    }

}

void Karakter (int x, int status) {

    if (status == 1) {
        string spasi (36/nama_karakter.size (), ' ');
        cout << spasi << nama_karakter << endl;
    }
    else {
        string spasi (3, ' ');
        cout << spasi << nama_karakter << endl;
    }

    switch (bentuk_karakter) {

        case 'a':
        Segitiga (6 + x, status);
        break;

        case 'b':
        Ketupat (6 + x, status);
        break;
    
        case 'c':
        cout << endl;
        Kotak (6 + x, status);
        break;

        case 'd':
        cout << endl;
        Trapesium (6 + x, status);
        break;

        default:
        cout << "Pesan error : Input tidak sesuai\n" << endl;
        break;
    
    }

}

void AI (int acak) {

    cout << "  YP-0" << 0 + (rand () % 99) << endl;

    switch (acak) {

        case 1 :
        Ketupat (0, 0);
        break;

        case 2 :
        cout << endl;
        Trapesium (0, 0);
        break;

        case 3 : 
        cout << endl;
        Kotak (3, 0);
        break;

        case 4 :
        Segitiga (0, 0);
        break; 

    }

}

// Atribut tambahan

void Kemampuan (int &atk, int &def, int val_atk, int val_def) {

    atk = atk + val_atk;
    def = def + val_def;

}

void Duid (int &uang, int tambah) {
    uang = uang + tambah;
}

int Nyerang (int atk_ku, int def_musuh) {

    int hasil = atk_ku - (def_musuh/30);
    return hasil;

}

// Mekanisme gamenya 

void Game_Suit () {

    int sign_AI, nyawa_AI = 1200;
    int sign_user, nyawa_user = 1200;

    int atk_AI = 0, def_AI = 0;

    atk_AI = 250 + (rand () % 900);
    def_AI = 220 + (rand () % 870);

    cout << "***** Game Suit *****\n" << endl;

    cout << "Semut = 1" << endl;
    cout << "Orang = 2" << endl;
    cout << "Gajah = 3" << endl << endl;
    
    cout << "^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    Karakter (-5, 0);

    cout << "\nAttack : " << attack << endl;
    cout << "Deffence : " << deffence << endl << endl;

    AI (1 + (rand () % 4));

    cout << "\nAttack : " << atk_AI << endl;
    cout << "Deffence : " << def_AI << endl;

    cout << "^^^^^^^^^^^^^^^^^^^^^^^\n" << endl;

    while (nyawa_user > 0 && nyawa_AI > 0) {

        cout << "Nyawa mu : " << nyawa_user << "\t\t|\tNyawa AI : " << nyawa_AI << endl;

        cout << "Masukan pilihan mu : ";
        cin >> sign_user;
        
        sign_AI = 1 + (rand () % 3);

        if (sign_user != 1 && sign_user != 2 && sign_user != 3) {
            cout << "\nError input\n" << endl;
        }

        else {

            cout << "\n" << sign_user << " lawan " << sign_AI << endl;

            if (sign_AI == 1 && sign_user == 1 || sign_AI == 2 && sign_user == 2 || sign_AI == 3 && sign_user == 3) {
                //Kalo seri
                cout << "Hasilnya seri" << endl << endl;
            }
            else if (sign_AI == 1 && sign_user == 3 || sign_AI == 2 && sign_user == 1 || sign_AI == 3 && sign_user == 2) {
                //Kalo kalah
                cout << "AI menyerang mu " << endl << endl;
                nyawa_user = nyawa_user - Nyerang (atk_AI, deffence);
            }
            else {
                //Kalo menang
                cout << "Kamu menyerang AI " << endl << endl;
                nyawa_AI = nyawa_AI - Nyerang (attack, def_AI);
            }

        }

    }

    if (nyawa_AI > 0) {
        cout << "\nKamu kalah\n" << endl;
    }

    else if (nyawa_user > 0){

        int tambah_duid = 2 + (rand () % 25); 

        cout << "Kamu menang" << endl;
        Duid (duid, tambah_duid);
        cout << "Kamu dapat " << tambah_duid << " LS\n" << endl;
        menang++;

    }

}