#pragma once
#include <string>
#include <iostream>
using namespace std;

class MyException
{
	string message;
public:
	MyException() throw()
		:message()
	{}
	string What() const throw() { return "Exception: MyException: " + message; }
	MyException(const string& msg) throw()
		:message(msg)
	{}
	virtual ~MyException() {}
};