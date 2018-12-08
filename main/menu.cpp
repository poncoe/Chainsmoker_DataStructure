//
// Created by Poncoe on 23/11/18.
//

#include <iostream>
#include "menu.h"
#include <stdlib.h>

// Membuat Sebuah Fungsi Untuk Melanjutkan

void Continue() {
    char k;
    cout << "\nMasukan 0 Untuk Melanjutkan : ";
    while( k != '0') {
        cin >> k;
    }
}

// Pilih Menu berdasarkan text

std::string getString (std::string text) {
    std::cout << text;
    std::string res;
//    std::cin.ignore(); //untuk membuat lebih dari 1 kata
//    std::getline(cin,res); //untuk membuat lebih dari 1 kata
    std::cin >> res;

    return res;
}

// Looping pada Menu

int pilihanMenu(string *pilihan, int Npilihan) {

    int res;

    for( int i = 0; i < Npilihan; i++) {
        std::cout << i + 1 << ". " << pilihan[i] << '\n';
    }

    std::cout << "\nMasukan Pilihan : ";
    std::cin >> res;

    return res;
}