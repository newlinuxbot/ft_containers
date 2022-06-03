#include "Vector.hpp"
#include <iostream>

using namespace std;

int main()
{
    ft::Vector<int> f(5);
    f.getArray()[0] = 1337;
    // ft::Vector<int> c(f);
    // cout << c.getArray()[0] << "\n";
    // ft::Vector<int> d = c;
    // cout << d.getArray()[0] << "\n";

    for (ft::Vector<int>::iterator i = f.begin(); i < f.end(); i++)
        cout << *i << endl;
    
    return 0;
}