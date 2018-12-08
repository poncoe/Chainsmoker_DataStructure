//
// Created by s3cretman on 11/20/2018.
//

#include "header.h"

// ========= GRUP ===========

// Mengalokasi Grup

addressGroup AllocateGroup(std::string data) {

    addressGroup P;
    P = new Group;

    listNetizen Netizens;
    CreateListNetizen(info (P).Netizens);

    info (P).data = data;
    info (P).numberOfNetizens = 0;
    next (P) = nullptr;
    prev (P) = nullptr;

    return P;
}

// Membuat Address Nampilin Grup

addressGroup GetGroup(listGroup L, std::string username) {

    addressGroup P = first (L);

    while (P != nullptr ) {
        if (info(P).data == username)
            return P;
        P = next (P);
    }


    return nullptr;
}

// Membuat Address Hapus Grup (Delete First)

addressGroup DeleteFirstGroup(listGroup &L) {

    addressGroup P = first (L);

    if (P != nullptr) {
        if (P == last (L)) {
            first (L) = nullptr;
            last (L)  = nullptr;
        } else {
            first (L) = next (first (L));
            next (P) = nullptr;
            prev (first (L)) = nullptr;
        }
    }

    return P;
}

// Membuat Address Hapus Grup (Delete Last)

addressGroup DeleteLastGroup(listGroup &L) {

    addressGroup P = last (L);

    if (P != nullptr) {
        if (P == first (L)) {
            first (L) = nullptr;
            last (L)  = nullptr;
        }
        else {
            last (L) = prev(P);
            prev (P) = nullptr;
            next (last (L)) = nullptr;
        }
    }

    return P;
}

// Membuat Address Hapus Grup (Delete First & Delete Last)

addressGroup DeleteGroup(listGroup &L, addressGroup C) {

    addressGroup P = GetGroup(L, info (C).data);

    if (P != nullptr) {
        if (P == first (L)) {
            P = DeleteFirstGroup(L);
        } else if (P == last (L)) {
            P = DeleteLastGroup(L);
        } else {
            prev (next (P)) = prev (P);
            next (prev (P)) = next (P);
            next (P) = nullptr;
            prev (P) = nullptr;
        }
    }

    listNetizen Netizen = info (C).Netizens;

    while (first (Netizen) != nullptr) {
        DeleteLastNetizen (Netizen);
    }

    return P;

}

// Membuat List Grup

void CreateListGroup(listGroup &L) {
    first (L) = nullptr;
    last (L) = nullptr;
}

// Dealokasi Grup

void DeallocateGroup(addressGroup P) {
    delete P;
    P = nullptr;
}

// Membuat Address Tambah Data Grup (Insert First)

void InsertFirstGroup(listGroup &L, addressGroup C) {
    if (first (L) == nullptr) {
        first (L) = C;
        last (L) = C;
    } else {
        next (C) = first (L);
        prev (first (L)) = C;
        first (L) = C;
    }
}

// Membuat Address Tambah Data Grup (Insert Last)

void InsertLastGroup(listGroup &L, addressGroup C) {
    if(GetGroup(L, info(C).data) == nullptr) {
        if(last(L) == nullptr) {
            first(L) = C;
            last(L) = C;
        } else {
            prev(C) = last(L);
            next(last(L)) = C;
            last(L) = C;
        }
    }
    else {
        DeallocateGroup(C);
    }
}

// Membuat Address Tambah Data Grup (Insert After)

void InsertAfterGroup(listGroup &L, addressGroup Prec, addressGroup C) {
    if (Prec != nullptr)
        InsertLastGroup(L, C);
    else {
        next (C) = next (Prec);
        prev (C) = Prec;
        prev (next (Prec)) = C;
        next (Prec) = C;
    }
}

// Membuat Address Sort Data Grup

void sortGroup(listGroup &L1) {

    listGroup L2;
    CreateListGroup(L2);

    while (first (L1) != nullptr) {

        addressGroup P = DeleteLastGroup(L1);

        if (first (L2) == nullptr)
            InsertFirstGroup(L2, P);
        else if (info (P).numberOfNetizens <= info (first (L2)).numberOfNetizens)
            InsertFirstGroup(L2, P);
        else if (info (P).numberOfNetizens >= info (first (L2)).numberOfNetizens)
            InsertLastGroup(L2, P);
        else {
            addressGroup Q = first (L2);
            while (info (next (Q)).numberOfNetizens < info (P).numberOfNetizens)
                Q = next (Q);
            InsertAfterGroup(L2, Q, P);
        }

    }

    L1 = L2;
}

// Membuat Address Menampilkan Semua Data Grup

void viewAllGroup(listGroup L) {
    if (first (L) != nullptr && last (L) != nullptr) {
        addressGroup P = first(L);
        while (P != nullptr) {
            std::cout << "  " << info(P).data << '\n';
            P = next (P);
        }
    } else {
        std::cout << "DATA KOSONG\n";
    }

}

// Membuat Address Lihat Data Grup

void viewGroup(listGroup L, std::string username) {
    if (first (L) != nullptr && last (L) != nullptr) {
        addressGroup P = GetGroup(L, username);
        if (P == nullptr)
            std::cout << "Data Tidak Ada!";
        else {
            std::cout << "data Grup       : " << info (P).data;
            std::cout << "\nJumlah Netizen : " << info (P).numberOfNetizens;
            std::cout << "\nNama Netizen   : \n\n";
            viewAllNetizen(info (P).Netizens);
        }
    }
}

// ========= NETIZEN =========


// Membuat Alokasi pada Netizen

addressNetizen AllocateNetizen(std::string data) {

    addressNetizen P;
    P = new Netizen;

    listGroup Netizen;
    CreateListGroup(info (P).Netizen);

    info (P).data = data;
    info (P).numberofNetizen = 0;
    next (P) = nullptr;
    prev (P) = nullptr;

    return P;
}

// Nampilin Data Netizen

addressNetizen GetNetizen(listNetizen L, std::string username) {


    addressNetizen P = first (L);

    while (P != nullptr ) {
        if (info(P).data == username)
            return P;
        P = next (P);
    }


    return nullptr;
}

// Membuat Address Hapus Netizen (Delete First)

addressNetizen DeleteFirstNetizen(listNetizen &L) {

    addressNetizen P = first (L);

    if (P != nullptr) {
        if (P == last (L)) {
            last (L)  = nullptr;
            first (L) = nullptr;
        } else {
            first (L) = next (first (L));
            next (P) = nullptr;
            prev (first (L)) = nullptr;
        }
    }

    return P;
}

// Membuat Address Hapus Netizen (Delete Last)

addressNetizen DeleteLastNetizen(listNetizen &L) {

    addressNetizen P = last (L);

    if (P != nullptr) {
        if (P == first (L)) {
            last (L)  = nullptr;
            first (L) = nullptr;
        }
        else {
            last (L) = prev (P);
            prev (P) = nullptr;
            next (last (L)) = nullptr;
        }
    }

    return P;

}

// Membuat Address Hapus Netizen (Delete First & Delete Last)

addressNetizen DeleteNetizen(listNetizen &L, addressNetizen F) {

    addressNetizen P = GetNetizen(L, info (F).data);

    if (P != nullptr) {
        if (P == first (L))
            P = DeleteFirstNetizen(L);
        else if (P == last (L))
            P = DeleteLastNetizen(L);
        else {
            prev (next (P)) = prev (P);
            next (prev (P)) = next (P);
            next (P) = nullptr;
            prev (P) = nullptr;
        }
    }

    listGroup Netizen = info (F).Netizen;

    while (first (Netizen) != nullptr) {
        DeleteLastGroup(Netizen);
    }

    return P;
}

// Dealokasi Netizen

void DeallocateNetizen(addressNetizen P) {
    delete P;
    P = nullptr;
}

// Membuat Address Input Data Netizen (Insert First)

void InsertFirstNetizen(listNetizen &L, addressNetizen F) {
    if (first (L) == nullptr) {
        first (L) = F;
        last (L) = F;
    } else {
        next (F) = first (L);
        prev (first (L)) = F;
        first (L) = F;
    }
}

// Membuat Address Input Data Netizen (Insert Last)

void InsertLastNetizen(listNetizen &L, addressNetizen F) {
    if (GetNetizen (L, info (F).data) == nullptr) {
        if (last (L) == nullptr) {
            first (L) = F;
            last (L) = F;
        } else {
            prev (F) = last (L);
            next (last (L)) = F;
            last (L) = F;
        }
    }
    else {
        DeallocateNetizen(F);
    }
}

// Membuat Address Input Data Netizen (Insert After)

void InsertAfterNetizen(listNetizen &L, addressNetizen Prec, addressNetizen F) {
    if (Prec != nullptr)
        InsertLastNetizen(L, F);
    else {
        next (F) = next (Prec);
        prev (F) = Prec;
        prev (next (Prec)) = F;
        next (Prec) = F;
    }
}

// Membuat List Netizen

void CreateListNetizen(listNetizen &L) {
    first (L) = nullptr;
    last (L) = nullptr;
}

// Membuat Address Sort Data Netizen

void sortNetizen(listNetizen &L1) {
    listNetizen L2;
    CreateListNetizen(L2);

    while (first (L1) != nullptr) {

        addressNetizen P = DeleteLastNetizen(L1);

        if (first (L2) == nullptr)
            InsertFirstNetizen(L2, P);
        else if (info (P).numberofNetizen <= info (first (L2)).numberofNetizen)
            InsertFirstNetizen(L2, P);
        else if (info (P).numberofNetizen >= info (first (L2)).numberofNetizen)
            InsertLastNetizen(L2, P);
        else {
            addressNetizen Q = first (L2);
            while (info (next (Q)).numberofNetizen < info (P).numberofNetizen)
                Q = next (Q);
            InsertAfterNetizen(L2, Q, P);
        }
    }

    L1 = L2;
}

// Menampilkan Semua Data Netizen

void viewAllNetizen(listNetizen L) {
    if (first (L) != nullptr && last (L) != nullptr) {
        addressNetizen P = first(L);
        while (P != nullptr) {
            std::cout << info(P).data << '\n';
            P = next (P);
        }
    } else {
        std::cout << "DATA KOSONG\n";
    }
}

// Menampilkan Data Netizen

void viewNetizen(listNetizen L, std::string username) {
    if (first (L) != nullptr && last (L) != nullptr) {
        addressNetizen P = GetNetizen(L, username);
        if (P == nullptr)
            std::cout << "Data Tidak Ada"; // Kalo Datanya kaga ada

            // Kalo Datanya ada dia bakalan nampilin Netizen
        else {
            std::cout << "Data    : " << info(P).data << '\n';
            std::cout << "Jumlah Grup : " << info(P).numberofNetizen;
            std::cout << "\nGrup : \n\n";
            viewAllGroup(info (P).Netizen);
        }
    }
}