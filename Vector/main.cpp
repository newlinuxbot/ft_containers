#include "Vector.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // ft::Vector<int> f(5);
    // f.getArray()[0] = 1337;
    // f.getArray()[1] = 1444;
    // ft::Vector<int> c(f);
    // cout << c.getArray()[0] << "\n";
    // ft::Vector<int> d = c;
    // cout << d.getArray()[0] << "\n";

    // for (ft::Vector<int>::reverse_iterator i = f.rbegin(); i < f.rend(); i++)
    // {
    //     cout << *i << endl;
    // }

    // vector<int> vec(10);
    // vec.resize(20,11);
    // for (vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
    // {
    //     cout << *i << ' ';
    // }
    // cout << endl;
    // ft::Vector<int> ve(10);
    // ve.resize(20,11);
    // for (ft::Vector<int>::iterator i = ve.begin(); i < ve.end(); i++)
    // {
    //     cout << *i << ' ';
    // }
    // cout << endl;

    // ft::Vector<int> em;
    // cout << em.empty() << endl;
    // cout << ve.empty() << endl;
    // ve.reserve(70);

    // ft::Vector<int> ffffr(5);
    // cout << ffffr[4] << endl;

    // ft::Vector<int> fffr(5);
    // fffr[4] = 555;
    // cout << fffr.at(4) << endl;

    // cout << fffr.front() - fffr.back() << endl;

    // ft::Vector<int> a;
    // for (int i = 0; i < 200; i++)
    //     a.push_back(i);
    // for (ft::Vector<int>::iterator i = a.begin(); i < a.end(); i++)
    //     cout << *i << " ";

    // cout << endl;

    // a.pop_back();

    // for (ft::Vector<int>::iterator i = a.begin(); i < a.end(); i++)
    //     cout << *i << " ";
    // cout << endl;

    // ft::Vector<int> first;                                // empty vector of ints
    // ft::Vector<int> second (4,100);                       // four ints with value 100
    // ft::Vector<int> third (second.begin(),second.end());  // iterating through second
    // ft::Vector<int> fourth (third);                       // a copy of third

    // // the iterator constructor can also be used to construct from arrays:
    // int *myints = new int[4];
    // myints[0] = 16;
    // myints[1] = 2;
    // myints[2] = 77;
    // myints[3] = 29;
    // ft::Vector<int> fifth (myints, myints + 4 );

    // std::cout << "The contents of fifth are:";
    // for (ft::Vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    // ft::Vector<int> first;
    // ft::Vector<int> second;
    // ft::Vector<int> third;

    // first.assign (7,100);             // 7 ints with a value of 100

    // ft::Vector<int>::iterator it;
    // it=first.begin()+1;

    // second.assign (it,first.end()-1); // the 5 central values of first

    // int myints[] = {1776,7,4};
    // third.assign (myints,myints+3);   // assigning from array.

    // std::cout << "Size of first: " << int (first.size()) << '\n';
    // std::cout << "Size of second: " << int (second.size()) << '\n';
    // std::cout << "Size of third: " << int (third.size()) << '\n';

    // ft::Vector<int> v;
    // v.push_back(45);
    // v.push_back(13);
    // v.push_back(15);
    // v.insert(v.begin(), 777);
    // v.insert(v.end(), 100, 666);
    // // for(int i = 0;i < 100023;i++)
    // //     v.insert(v.end(), i);
    // for (ft::Vector<int>::iterator i = v.begin(); i < v.end(); i++)
    //     cout << *i << endl;
    

    ft::Vector<int> myvector (3,100);
    ft::Vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

    myvector.insert (it,2,300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    ft::Vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
}