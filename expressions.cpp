#include "expressions.hpp"
#include "utils.hpp"

Factor::Factor(std::stringstream& is) {
    char c = is.get();
    if (Number::isFirstNumberChar(c)) {
        is.unget();
        Number num(is);
        value = num.getValue();
    } else if (c == '(') {
        skipSpaces(is);
        Expression expr(is);
        skipSpaces(is);
        char rightParen = is.get();
        value = expr.getValue();
    }
}

Term::Term(std::stringstream& is) {
    Factor lhs(is);
    skipSpaces(is);

    value = lhs.getValue();

    char c = is.get();
    while ((c == '*') || (c == '/') || (!(c == '-') && Factor::isFirstFactorChar(c))) {
        if (c == '*') {
            skipSpaces(is);
            Factor rhs(is);
            value *= rhs.getValue();
        } else if (c == '/') {
            skipSpaces(is);
            Factor rhs(is);
            value /= rhs.getValue();
        } else if (Factor::isFirstFactorChar(c)) {
            is.unget();
            Factor rhs(is);
            value *= rhs.getValue();
        }
        c = is.get();
    }
    is.unget();
}

Expression::Expression(std::stringstream& is) {
    char first = is.get();
    is.unget();
    if ((first == '+') || (first == '-')) {
        value = 0;
    } else {
        Term lhs(is);
        value = lhs.getValue();
        skipSpaces(is);
    }

    char c = is.get();
    while ((c == '+') || (c == '-')) {
        if (c == '+') {
            skipSpaces(is);
            Term rhs(is);
            value += rhs.getValue();
        } else if (c == '-') {
            skipSpaces(is);
            Term rhs(is);
            value -= rhs.getValue();
        }
        c = is.get();
    }
    is.unget();
}
