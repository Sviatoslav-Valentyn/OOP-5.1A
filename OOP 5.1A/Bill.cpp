#include "Bill.h"
#include <sstream>

Bill::Bill()
{
	first = 0;
	second = 0;
}

Bill::Bill(int f = 0, double s = 0) throw(invalid_argument)
{
	if (f < 0 || s < 0)
		throw invalid_argument("first < 0 || second < 0");
	first = f;
	second = s;
}

Bill::Bill(const Bill& r)
{
	first = r.first;
	second = r.second;
}

Bill::~Bill()
{ }

void Bill::SetFirst(int value) throw(invalid_argument)
{
	if (value < 0)
		throw invalid_argument("value < 0");
	first = value;
}

void Bill::SetSecond(double value) throw(MyException)
{
	if (value < 0)
		throw MyException("value < 0");
	second = value;
}

double Bill::Cost()
{
	return first * second;
}

Bill& Bill::operator = (const Bill& r)
{
	first = r.first;
	second = r.second;

	return *this;
}

istream& operator >> (istream& input, Bill& m)
{
	int f;
	double s;
	cout << " first = "; input >> m.first;
	cout << " second = "; input >> m.second;
	cout << endl;

	return input;
}

ostream& operator << (ostream& output, const Bill& l)
{
	output << string(l);
	return output;
}

Bill::operator string() const
{
	stringstream p;
	p << " first = " << first << endl;
	p << " second = " << second << endl;
	return p.str();
}

Bill& Bill::operator ++()
{
	first++;
	return *this;
}

Bill Bill::operator ++(int)
{
	Bill t(*this);
	second++;
	return t;
}

Bill& Bill::operator --() throw(MyDeliveredException)
{
	first--;
	if (first == 0)
		throw new MyDeliveredException();
	return *this;
}

Bill Bill::operator --(int) throw(MyDeliveredException)
{
	Bill a(*this);
	second--;
	if (second == 0)
		throw MyDeliveredException();
	return a;
}