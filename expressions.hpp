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
};

class Factor : public Valuable {
public:
    Factor(std::stringstream& is);
};

class Term : public Valuable {
public:
    Term(std::stringstream& is);
};

class Expression : public Valuable {
public:
    Expression(std::stringstream& is);
};
