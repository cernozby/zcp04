//
// Created by Zbysa on 11.03.2022.
//

#ifndef UNTITLED9_SEZNAM_H
#define UNTITLED9_SEZNAM_H


class Seznam {
private:
    static Seznam *Prvni, *Posledni, *Iterator;
    char *Retez;
    Seznam *Predchozi,*Dalsi;
public:
    Seznam(const char *ret, bool konec=false);
    const char *data() const;
    static bool prvni();
    static bool posledni();
    static Seznam *soucasny();
    static bool dalsi();
    static bool predchozi();
};


#endif //UNTITLED9_SEZNAM_H
