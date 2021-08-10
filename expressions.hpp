#pragma once

#include <sstream>

class Valuable {
public:
    int getValue() {
        return value;
    }
protected:
    int value = 0;
};

class Number : public Valuable {
public:
    Number(std::stringstream& is) {
        is >> value;
    }

    static bool isFirstNumberChar(char c) {
        return ((c >= '0') && (c <= '9')) || (c == '-');
    }
};

class Factor : public Valuable {
public:
    Factor(std::stringstream& is);

    static bool isFirstFactorChar(char c) {
        return Number::isFirstNumberChar(c) || (c == '(');
    }
};

class Term : public Valuable {
public:
    Term(std::stringstream& is);
};

class Expression : public Valuable {
public:
    Expression(std::stringstream& is);
};
