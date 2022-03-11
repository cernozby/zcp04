#include <iostream>
#include <cstring>
#include "seznam.h"

int main() {

    //testovaci vypisy
    new Seznam("prvni", true);
    new Seznam("druhy", true);
    new Seznam("treti", true);
    new Seznam("nulty", false);

    std::cout << Seznam::prvni() << std::endl;
    std::cout << Seznam::soucasny()->data() << std::endl;
    std::cout << Seznam::dalsi() << std::endl;
    std::cout << Seznam::soucasny()->data() << std::endl;
    std::cout << Seznam::dalsi() << std::endl;
    std::cout << Seznam::soucasny()->data() << std::endl;

    Seznam::posledni();
    while(Seznam::predchozi()) {
        std::cout << Seznam::soucasny()->data() << std::endl;
    }
}
