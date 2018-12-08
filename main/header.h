//
// Created by s3cretman on 11/20/2018.
//

#ifndef CHAINSMOKER_PROJECTSTD_NETIZEN_H
#define CHAINSMOKER_PROJECTSTD_NETIZEN_H

#include <iostream>
#include <string>

// List Makro

#define first(L) (L).first
#define last(L)  (L).last
#define next(P)  (P)->next
#define prev(P)  (P)->prev
#define info(P)  (P)->info

// List Deklarasi

typedef struct Netizen *addressNetizen;
typedef struct Group *addressGroup;

struct listNetizen {
    addressNetizen first;
    addressNetizen last;
};


struct listGroup {
    addressGroup first;
    addressGroup last;
};

// Struktur Data Grup

struct infotypeGroup {
    std::string data;
    int numberOfNetizens;
    listNetizen Netizens;
};

struct Group {
    infotypeGroup info;
    addressGroup next;
    addressGroup prev;
};

addressGroup AllocateGroup(std::string data);
addressGroup GetGroup(listGroup L, std::string username);
addressGroup DeleteFirstGroup(listGroup &L);
addressGroup DeleteLastGroup(listGroup &L);
addressGroup DeleteGroup(listGroup &L, addressGroup C);

void CreateListGroup(listGroup &L);
void DeallocateGroup(addressGroup C);
void InserFirstGroup(listGroup &L, addressGroup C);
void InsertLastGroup(listGroup &L, addressGroup C);
void InsertAfterGroup(listGroup &L, addressGroup Prec, addressGroup C);
void sortGroup(listGroup &L1);
void viewAllGroup(listGroup L);
void viewGroup(listGroup L, std::string username);

// Struktur Data Netizen

struct infotypeNetizen {
    std::string data;
    int numberofNetizen;
    struct listGroup Netizen;
};

struct Netizen {
    infotypeNetizen info;
    addressNetizen next;
    addressNetizen prev;
};

addressNetizen AllocateNetizen(std::string data);
addressNetizen GetNetizen(listNetizen Netizen, std::string username);
addressNetizen DeleteNetizen(listNetizen &L, addressNetizen C);
addressNetizen DeleteFirstNetizen(listNetizen &L);
addressNetizen DeleteLastNetizen(listNetizen &L);

void CreateListNetizen(listNetizen &L);
void DeallocateNetizen(addressNetizen F);
void InsertFirstNetizen(listNetizen &L, addressNetizen F);
void InsertLastNetizen(listNetizen &L, addressNetizen F);
void InsertAfterNetizen(listNetizen &L, addressNetizen Prec, addressNetizen F);
void sortNetizen(listNetizen &L1);
void viewAllNetizen(listNetizen L);
void viewNetizen(listNetizen L, std::string username);

#endif //CHAINSMOKER_PROJECTSTD_NETIZEN_H
