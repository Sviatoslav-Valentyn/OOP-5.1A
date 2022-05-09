#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <exception>
#include "MyException.h"
#include "MyDeliveredException.h"
using namespace std;

class Bill
{
	int first;
	double second;
public:
	Bill(); // конструктор за умовчанням
	Bill(int, double) throw (invalid_argument); // конструктор ініціалізації
	Bill(const Bill&); //копіювання
	~Bill();

	int GetFirst() const { return first; };
	double GetSecond() const { return second; };
	void SetFirst(int f) throw(invalid_argument);
	void SetSecond(double s) throw(MyException);
	double Cost();

	Bill& operator = (const Bill&); // присвоєння
	friend istream& operator >> (istream&, Bill&) throw (invalid_argument); //введення з клавіатури
	friend ostream& operator << (ostream&, const Bill&); //вивід на екран
	operator string() const; //приведення типу – перетворення у літерний рядок

	Bill& operator ++(); // префіксний інкремент (first)
	Bill operator ++(int); // постфіксний інкремент (second)
	Bill& operator --() throw(MyDeliveredException); // префіксний декремент (first)
	Bill operator --(int) throw(MyDeliveredException); // постфіксний декремент (second)
};