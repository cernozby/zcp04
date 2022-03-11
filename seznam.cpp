#include "seznam.h"
#include <iostream>
#include <cstring>

using namespace std;

Seznam *Seznam::Prvni = nullptr;
Seznam *Seznam::Posledni = nullptr;
Seznam *Seznam::Iterator = nullptr;


Seznam::Seznam(const char *ret, bool konec) {
    Retez = (char *)malloc(strlen(ret) + 1);
    strcpy(this->Retez, ret);
    if (konec) {

        Dalsi = nullptr;
        Predchozi = Seznam::Posledni;

        //druhy a dalsi uzel
        if (Seznam::Posledni && Seznam::Prvni) {
            Seznam::Posledni->Dalsi = this;
            Seznam::Posledni = this;
        } else {
            Seznam::Posledni = Seznam::Prvni = this;
        }
    } else {
        Dalsi = Seznam::Prvni;
        Predchozi = nullptr;

        //druhy a dalsi uzel
        if (Seznam::Posledni && Seznam::Prvni) {
            Seznam::Prvni->Predchozi = this;
            Seznam::Prvni = this;
        } else {
            Seznam::Posledni = Seznam::Prvni = this;
        }
    }
}

const char *Seznam::data() const {
  return Retez;
}

bool Seznam::dalsi() {
    if (!Seznam::Iterator->Dalsi) {return false;}
    Seznam::Iterator = Seznam::Iterator->Dalsi;
    return true;
}

bool Seznam::predchozi() {
    if (!Seznam::Iterator->Predchozi) {return false;}
    Seznam::Iterator = Seznam::Iterator->Predchozi;
}

bool Seznam::prvni() {
    if (!Seznam::Prvni) {return false;}
    Seznam::Iterator = Seznam::Prvni;
    return true;
}


bool Seznam::posledni() {
    if (!Seznam::Posledni) {return false;}
    Seznam::Iterator = Seznam::Posledni;
    return true;
}

Seznam *Seznam::soucasny() {
    return Iterator;
}