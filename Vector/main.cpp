#include "Vector.hpp"
#include <iostream>
#include <vector>
#include "iterator.hpp"

using namespace std;

bool mypredicate (int i, int j) {
  return (i==j);
}

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
    

    // ft::Vector<int> myvector (3,100);
    // ft::Vector<int>::iterator it;

    // it = myvector.begin();
    // it = myvector.insert ( it , 200 );

    // myvector.insert (it,2,300);

    // // "it" no longer valid, get a new one:
    // it = myvector.begin();

    // ft::Vector<int> anothervector (2,400);
    // myvector.insert (it+2,anothervector.begin(),anothervector.end());

    // int myarray [] = { 501,502,503 };
    // myvector.insert (myvector.begin(), myarray, myarray+3);

    // std::cout << "myvector contains:";
    // for (it=myvector.begin(); it<myvector.end(); it++)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

//     ft::Vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element
//   myvector.erase (myvector.begin()+5);

//   // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.begin()+3);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//     ft::Vector<int> foo (3,100);   // three ints with a value of 100
//     ft::Vector<int> bar (5,200);   // five ints with a value of 200

//     foo.swap(bar);

//     std::cout << "foo contains:";
//     for (unsigned i=0; i<foo.size(); i++)
//         std::cout << ' ' << foo[i];
//     std::cout << '\n';

//     std::cout << "bar contains:";
//     for (unsigned i=0; i<bar.size(); i++)
//         std::cout << ' ' << bar[i];
//     std::cout << '\n';

    // ft::Vector<int> myvector;
    // myvector.push_back (100);
    // myvector.push_back (200);
    // myvector.push_back (300);

    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector.size(); i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';

    // myvector.clear();
    // myvector.push_back (1101);
    // myvector.push_back (2202);

    // std::cout << "myvector contains:";
    // for (unsigned i=0; i<myvector.size(); i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';

    // int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
    // std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

    // // using default comparison:
    // if ( std::equal (myvector.begin(), myvector.end(), myints) )
    //     std::cout << "The contents of both sequences are equal.\n";
    // else
    //     std::cout << "The contents of both sequences differ.\n";

    // myvector[3]=81;                                 // myvector: 20 40 60 81 100

    // // using predicate comparison:
    // if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
    //     std::cout << "The contents of both sequences are equal.\n";
    // else
    //     std::cout << "The contents of both sequences differ.\n";

    // std::vector<int> foo (3,100);   // three ints with a value of 100
    // std::vector<int> bar (2,200);   // two ints with a value of 200

    // if (foo==bar) std::cout << "foo and bar are equal\n";
    // if (foo!=bar) std::cout << "foo and bar are not equal\n";
    // if (foo< bar) std::cout << "foo is less than bar\n";
    // if (foo> bar) std::cout << "foo is greater than bar\n";
    // if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    // if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    
    ft::Vector<int> v;
    v.push_back(21);
    v.push_back(33);
    v.push_back(44);

    for (ft::reverse_iterator<int> i = v.rbegin(); i != v.rend(); ++i)
      cout << *i << endl;

  return 0;
}
