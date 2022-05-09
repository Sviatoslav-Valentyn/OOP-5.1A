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
	Bill(); // ����������� �� ����������
	Bill(int, double) throw (invalid_argument); // ����������� �����������
	Bill(const Bill&); //���������
	~Bill();

	int GetFirst() const { return first; };
	double GetSecond() const { return second; };
	void SetFirst(int f) throw(invalid_argument);
	void SetSecond(double s) throw(MyException);
	double Cost();

	Bill& operator = (const Bill&); // ���������
	friend istream& operator >> (istream&, Bill&) throw (invalid_argument); //�������� � ���������
	friend ostream& operator << (ostream&, const Bill&); //���� �� �����
	operator string() const; //���������� ���� � ������������ � ������� �����

	Bill& operator ++(); // ���������� ��������� (first)
	Bill operator ++(int); // ����������� ��������� (second)
	Bill& operator --() throw(MyDeliveredException); // ���������� ��������� (first)
	Bill operator --(int) throw(MyDeliveredException); // ����������� ��������� (second)
};