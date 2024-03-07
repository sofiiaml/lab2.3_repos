//2.3.cpp
#include <iostream>
#include <string>
#include <sstream>
#include "FuzzyNumber.h"

using namespace std;

int main() {
    FuzzyNumber a(3.0, 1.0, 2.0);
    double x, l, r;
    cout << "x: ";cin >> x;
    cout << "l: ";cin >> l;
    cout << "r: ";cin >> r;
    FuzzyNumber b(x, l, r);

    FuzzyNumber c = a + b;
    FuzzyNumber d = a - b;
    FuzzyNumber e = a * b;
    FuzzyNumber f = a / b;

    cout << "a + b: " << endl;cout << c << endl;
    cout << "a - b: " << endl;cout << d << endl;
    cout << "1 / a: " << endl;cout << e << endl;
    cout << "a / b: " << endl;cout << f << endl;
    cout << "++a: " << endl;cout << ++a << endl;
    cout << "--b: " << endl;cout << --b << endl;
    cout << "c++: " << endl;cout << c++ << endl;
    cout << "d--: " << endl;cout << d-- << endl;

    return 0;
}