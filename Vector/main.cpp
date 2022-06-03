#include "Vector.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ft::Vector<int> f(5);
    f.getArray()[0] = 1337;
    f.getArray()[1] = 1444;
    ft::Vector<int> c(f);
    cout << c.getArray()[0] << "\n";
    ft::Vector<int> d = c;
    cout << d.getArray()[0] << "\n";

    for (ft::Vector<int>::reverse_iterator i = f.rbegin(); i < f.rend(); i++)
    {
        cout << *i << endl;
    }

    vector<int> vec(10);
    vec.resize(20,11);
    for (vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
    {
        cout << *i << ' ';
    }
    cout << endl;
    ft::Vector<int> ve(10);
    ve.resize(20,11);
    for (ft::Vector<int>::iterator i = ve.begin(); i < ve.end(); i++)
    {
        cout << *i << ' ';
    }
    cout << endl;

    ft::Vector<int> em;
    cout << em.empty() << endl;
    cout << ve.empty() << endl;
    ve.reserve(70);

    ft::Vector<int> ffffr(5);
    cout << ffffr[4] << endl;

    ft::Vector<int> fffr(5);
    fffr[4] = 555;
    cout << fffr.at(4) << endl;

    cout << fffr.front() - fffr.back() << endl;

    return 0;
}