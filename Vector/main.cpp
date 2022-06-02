#include "Vector.hpp"
#include <iostream>

using namespace std;

int main()
{
    ft::Vector<int> f;
    f.getArray()[0] = 1337;
    ft::Vector<int> c(f);
    cout << c.getArray()[0] << "\n";
    ft::Vector<int> d = c;
    cout << d.getArray()[0] << "\n";
    return 0;
}