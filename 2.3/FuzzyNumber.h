//FuzzyNUmber.h
#pragma once
#include<string>
using namespace std;

class FuzzyNumber {
private:
	double x;
	double l;
	double r;
public:
	double getX() const { return x; }
	double getL() const { return l; }
	double getR() const { return r; }

	void setX(double value) { x = value; }
	void setL(double value) { l = value; }
	void setR(double value) { r = value; }

	FuzzyNumber();//за замовчуванням
	FuzzyNumber(double x, double l, double r);//ініціалізації
	FuzzyNumber(const FuzzyNumber&);//конструктор копіювання
	operator string() const;
	FuzzyNumber& operator=(const FuzzyNumber& f);//оператор присвоєння

	FuzzyNumber& operator ++();
	FuzzyNumber& operator --();
	FuzzyNumber operator++(int);
	FuzzyNumber operator--(int);

	FuzzyNumber operator+(const FuzzyNumber& f) const;
	FuzzyNumber operator-(const FuzzyNumber& f) const;
	FuzzyNumber operator/(const FuzzyNumber& f) const;
	FuzzyNumber operator*(const FuzzyNumber& f) const;
	
	friend ostream& operator<<(ostream& out, const FuzzyNumber& f);
	friend istream& operator>>(istream& in, FuzzyNumber& f);
};