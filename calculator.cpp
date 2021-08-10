#include <iostream>
#include <sstream>
#include <string>

#include "expressions.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    string inputLine;
    while (getline(cin, inputLine)) {
        if (inputLine == "quit") {
            break;
        }

        stringstream is(inputLine);
        skipSpaces(is);

        Expression expr(is);
        cout << expr.getValue() << endl;
    }
    return 0;
}
