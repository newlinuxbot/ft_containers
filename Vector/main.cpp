#include "vector.hpp"
#include <iostream>
#include <vector>


using namespace std;

bool mypredicate (int i, int j) {
  return (i==j);
}

int main()
{
  ft::vector<int> a;
  a.assign(50,400);
  for (ft::reverse_iterator<int> i = a.rbegin(); i != a.rend(); i++)
  {
    cout << *i << " ";
  }
}
