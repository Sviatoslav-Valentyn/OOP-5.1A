#include "Bill.h"
#include <iostream>
using namespace std;

Bill makeBill(int f, double s)
{
    Bill b(f, s);
    return b;
}

void _unexpected_to_bad()
{
    cerr << "bad_exception" << endl;
    throw;
}

int main()
{

    set_unexpected(_unexpected_to_bad);
    set_terminate(_unexpected_to_bad);

    try
    {
        Bill b;
        cin >> b;
        cout << "Cost = " << b.Cost() << endl;
    }
    catch (invalid_argument a)
    {
        cerr << "Exception b: " << a.what() << endl;
    }

    cout << "========================================================" << "\nBill b2:\n";

    try
    {
        Bill b2 = makeBill(2, 1);
        cout << "b2:\n" << b2;
        cout << "Cost = " << b2.Cost() << endl;

        try
        {
            b2--;
            --b2;
        }
        catch (MyDeliveredException* m)
        {
            cerr << m->What() << endl;
        }
        catch (MyDeliveredException& m)
        {
            cerr << m.What() << endl;
        }

    }
    catch (invalid_argument a)
    {
        cerr << "Exception b2: " << a.what() << endl;
    }
  
    cout << "========================================================";
    return 0;
}