#include "utils.hpp"

#include <sstream>

void skipSpaces(std::stringstream& is) {
    char c;
    do {
        c = is.get();
    } while (c == ' ');
    is.unget();
}
