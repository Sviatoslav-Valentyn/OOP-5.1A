#pragma once
#include<exception>
#include<iostream>
using namespace std;

class MyDeliveredException : public exception
{
public:
	virtual const char* What() const throw() { return "Exception: MyDeliveredException: value = 0"; }
};