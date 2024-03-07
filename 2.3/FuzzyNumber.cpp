//FuzzyNumber.cpp
#include "FuzzyNumber.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

FuzzyNumber::FuzzyNumber()
	: x(0), l(0), r(0) 
{}
FuzzyNumber::FuzzyNumber(double x_value, double l_value, double r_value) {
	setX(x_value); setL(l_value); setR(r_value);
}
FuzzyNumber::FuzzyNumber(const FuzzyNumber& f) {
	*this = f;
}
FuzzyNumber& FuzzyNumber::operator=(const FuzzyNumber& f) {
		x = f.x;
		l = f.l;
		r = f.r;
	return *this;
}
FuzzyNumber FuzzyNumber::operator+(const FuzzyNumber& f) const {
	return FuzzyNumber(x + f.x - l - f.l, x + f.x, x + f.x + r + f.r);
}
FuzzyNumber FuzzyNumber::operator-(const FuzzyNumber& f) const {
	return FuzzyNumber(x - f.x - l - f.l, x - f.x, x - f.x + r + f.r);
}
FuzzyNumber FuzzyNumber::operator*(const FuzzyNumber& f) const {
	if (x > 0) {
		return FuzzyNumber(1.0 / (x + r), 1.0 / x, 1.0 / (x - l));
	}
	return FuzzyNumber();
}
FuzzyNumber FuzzyNumber::operator/(const FuzzyNumber& f) const {
	if (f.x > 0) {
		return FuzzyNumber( (x - f.l) / (f.x + f.r), x / f.x, (x + r) / (f.x - f.l) );
	}
	return FuzzyNumber();
}
FuzzyNumber& FuzzyNumber::operator ++() {
	x++; l++; r++;
	return *this;
}
FuzzyNumber& FuzzyNumber::operator --() {
	x--; l--; r--;
	return *this;
}
FuzzyNumber FuzzyNumber::operator++(int) {
	FuzzyNumber tmp = *this;
	++*this;
	return tmp;
}
FuzzyNumber FuzzyNumber::operator--(int) {
	FuzzyNumber tmp = *this;
	--(*this);
	return tmp;
}
FuzzyNumber::operator string() const {
	stringstream sout;

	sout << "x:" << x << endl;
	sout << "l:" << l << endl;
	sout << "r:" << r << endl;
	return sout.str();
}
ostream& operator<<(ostream& out, const FuzzyNumber& f) {
	out << string(f);
	return out;
}
istream& operator>>(istream& in, FuzzyNumber& f) {
	double x, l, r;
	cout << "x:";in >> x;
	cout << "l:";in >> l;
	cout << "r:";in >> r;
	return in;
}