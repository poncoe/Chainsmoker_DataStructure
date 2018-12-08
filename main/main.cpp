#include <iostream>
#include <regex>
#include "welcome.h"
#include "menu.h"
#include "header.h"

using namespace std;

//==================================== MAIN PROGRAM =======================================

// Membuat Address & List Pada Program

listGroup L_C;
listNetizen L_F;

addressGroup adrGrup;
addressNetizen adrNetizen;

int state = 0;

void init () {
    CreateListGroup(L_C);
    CreateListNetizen(L_F);
}

// Membuat Sebuah Relasi Saling Terhubung

void Relasi(string Group, string Netizen) {
    addressGroup C = GetGroup(L_C, Group);
    addressNetizen F = GetNetizen(L_F, Netizen);

    //Kalo Ada
    if (C != nullptr && F != nullptr) {
        if (GetNetizen(info(C).Netizens, Netizen) == nullptr) {
            InsertLastNetizen(info(C).Netizens, AllocateNetizen(Netizen));
            info(C).numberOfNetizens++;
            sortGroup(L_C);
        } else // Kalo Udah Ada
            cout << "Netizen sudah ada";

        //Kalo Belom ada
        if (GetGroup(info(F).Netizen, Group) == nullptr) {
            InsertLastGroup(info(F).Netizen, AllocateGroup(Group));
            info(F).numberofNetizen++;
            sortNetizen(L_F);
        } else // Kalo Udah Ada
            cout << "Grup Sudah Ada";
    } else {
        cout << "data grup atau netizen tidak ada";
    }

}

// Membuat Sebuah Relasi Tidak Terhubung

void TidakRelasi(string Grup, string Netizen) {
    addressGroup C = GetGroup(L_C, Grup);
    addressNetizen F = GetNetizen(L_F, Netizen);

    //Kalo Ada
    if (C != nullptr && F != nullptr) {
        if (GetNetizen(info(C).Netizens, Netizen) != nullptr) {
            DeleteNetizen(info(C).Netizens, GetNetizen(info(C).Netizens, Netizen));
            info(C).numberOfNetizens--;
        } else //Kalo Udah Ada
            cout << "data tidak ada";

        //Kalo Belom Ada
        if (GetGroup(info(F).Netizen, Grup) != nullptr) {
            DeleteGroup(info(F).Netizen, GetGroup(info(F).Netizen, Grup));
            info(F).numberofNetizen--;
        } else //Kalo Udah Ada
            cout << "data tidak ada";
    } else {
        cout << "data grup atau netizen tidak ada";
    }

}

// Main Program

int main () {
    cout<<""<<endl;
    welcomeIndo(); // Manggil si WelcomeIndo yang ada di welcome.cpp sebelumnya via welcome.h dulu
    init(); //manggil list grup dan netizen

    //Membuat sebuah String untuk menu yang berisikan 8 String
    string menu[8] = {
            "Menu Grup",
            "Menu Netizen",
            "Tampilkan semua Data Netizen dan Grup",
            "Menampilkan Grup tertentu dan Netizen-nya",
            "Menampilkan Grup teratas dan Netizen-nya",
            "Menampilkan Semua Netizen dan Yang Berelasi",
            "Tunjukkan Netizen tertentu dan Berelasi",
            "Keluar dari Aplikasi"
    };
    cout << "Pilih Menu yang ingin anda Panggil :\n\n";
    state = pilihanMenu(menu, 8); // ini yang 4 harus sesuai kalo menunya ada 8 berati di state harus / sampe 8

    //Perulangan pada menu
    while (state != -1) {
        cout<<""<<endl;
        if (state == 0){
            cout << "Pilih Menu yang ingin anda pilih :\n\n";
            state = pilihanMenu(menu, 8); // ini yang 8 harus sesuai kalo menunya ada 8 berati di state harus / sampe 8
        }else
        if (state == 1) { // State 1 yaitu Menu ke 1 (Menu Grup)
            cout<<""<<endl;
            string submenu[3] = {
                    "Tambah Data",
                    "Hapus Data",
                    "Kembali"
            };
            int substate = pilihanMenu(submenu, 3); // ini yang 3 harus sesuai kalo menunya ada 3 berati di state harus / sampe 3
            cout<<""<<endl;

            //Isi Dari Menu Ke 1
            while(substate != -1) {
                if (substate == 0) {
                    substate = pilihanMenu(submenu, 3); // ini yang 3 harus sesuai kalo menunya ada 3 berati di state harus / sampe 3
                }
                if (substate == 1) {
                    InsertLastGroup (L_C, AllocateGroup(getString("Masukan Data Grup Baru : ")));
                    substate = 0;
                } else
                if (substate == 2) {
                    string data = getString("Masukan Data Grup yang akan dihapus : ");
                    DeleteGroup(L_C, GetGroup(L_C, data)); // Hapus Data Grup (Delete Last)
                    addressNetizen P = first (L_F);
                    while (P != nullptr) {
                        DeleteGroup(info(P).Netizen, GetGroup(info(P).Netizen, data)); // Hapus Data Grup (Delete Last)
                        P = next(P);
                    }
                    substate = 0;
                } else if (substate == 3) {
                    substate = -1;
                } else substate = 0;
            }

            state = 0;
        } else
        if (state == 2) { // State 2 yaitu Menu ke 2 (Menu Netizen)
            cout<<""<<endl;
            string submenu[5] = { //Membuat sebuah String untuk menu yang berisikan 5 String
                    "Tambah Data",
                    "Relasi Netizen",
                    "Tidak Relasi Netizen",
                    "Hapus Data",
                    "Kembali"
            };
            int substate = pilihanMenu(submenu, 5); // ini yang 5 harus sesuai kalo menunya ada 5 berati di state harus / sampe 5
            cout<<""<<endl;

            // Isi Dari Menu Netizen
            while(substate != -1) {
                cout<<""<<endl;
                if (substate == 0) {
                    substate = pilihanMenu(submenu, 5); // ini yang 5 harus sesuai kalo menunya ada 5 berati di state harus / sampe 5
                }
                if (substate == 1) {
                    InsertFirstNetizen (L_F, AllocateNetizen(getString("Masukan data netizen baru : ")));
                    substate = 0;
                } else
                if (substate == 2) {
                    Relasi(getString("masukan data grup : "), getString("Masukan data netizen baru : "));
                    Continue(); // Memasukan fungsi untuk melanjutkan
                    substate = 0;
                } else
                if (substate == 3) {
                    TidakRelasi(getString("masukan data grup : "), getString("Masukan data netizen baru : "));
                    Continue(); // Memasukan fungsi untuk melanjutkan
                    substate = 0;
                } else
                if (substate == 4) {
                    string data = getString("masukan data netizen yang akan dihapus : ");
                    DeleteNetizen(L_F, GetNetizen(L_F, data)); // Menghapus Data Netizen (Delete Last)
                    addressGroup P = first (L_C);
                    while (P != nullptr) {
                        DeleteNetizen(info(P).Netizens, GetNetizen(info(P).Netizens, data)); // Menghapus Data Netizen (Delete Last)
                        P = next(P);
                    }
                    substate = 0;
                } else if (substate == 5) { // ini yang 5 harus sesuai kalo menunya ada 5 berati di state harus / sampe 5
                    substate = -1;
                } else substate = 0;
            }

            state = 0;
        } else
        if (state == 3){ // State 3 yaitu Menu ke 3 (Menu Keluar Aplikasi)
            addressGroup C = first (L_C);

            while (C != nullptr){
                cout << "================================\n";
                cout << "Berikut adalah Data dari Grup\n";
                cout << "================================\n";
                viewGroup (L_C, info(C).data); // Menampilkan Data Grup
                cout << "========================";
                cout << '\n';
                C = next (C);
            }

            Continue(); // Memasukan fungsi untuk melanjutkan
            state = pilihanMenu(menu, 8);
        } else
        if (state == 4){ // State 4 yaitu Menu ke 4 (Menu Keluar Aplikasi)
            viewGroup(L_C, getString("Masukan Data Grup : ")); // input data grup
            Continue(); // Memasukan fungsi untuk melanjutkan
            state = pilihanMenu(menu, 8);
        } else
        if (state == 5){ // State 4 yaitu Menu ke 4 (Menu Keluar Aplikasi)
            viewGroup(L_C, info(last(L_C)).data); // Hapus Data Grup
            Continue(); // Memasukan fungsi untuk melanjutkan
            state = pilihanMenu(menu, 8);
        } else
        if (state == 6){ // State 4 yaitu Menu ke 4 (Menu Keluar Aplikasi)
            addressNetizen F = first (L_F);

            while (F != nullptr){
                cout << "================================\n";
                cout << "Berikut adalah Data dari Netizen\n";
                cout << "================================\n";
                viewNetizen (L_F, info(F).data); // Menampilkan Data Netizen
                cout << "========================";
                cout << '\n';
                F = next (F);
            }
            Continue(); // Memasukan fungsi untuk melanjutkan
            state = pilihanMenu(menu, 8);
        } else
        if (state == 7){ // State 4 yaitu Menu ke 4 (Menu Keluar Aplikasi)
            viewNetizen(L_F, getString("Masukan Data Netizen: ")); // Input Data Netizen
            Continue(); // Memasukan fungsi untuk melanjutkan
            state = pilihanMenu(menu, 8);

        } else
        if (state == 8){ // State 4 yaitu Menu ke 4 (Menu Keluar Aplikasi)
            state = -1;
            goodByeFromOtherSide();

            //Fixing Infinite Loop when Invalid Choice Menu by Hilman Abdan (github : @mystald)
        } else
        if (state > -1){
            state = -1;
            menuSalah();
        }
        cout<<""<<endl;

    }

    return 0;
}
