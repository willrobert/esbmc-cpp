// deque::rbegin/rend
#include <iostream>
#include <deque>
#include <cassert>

int main ()
{
  std::deque<int> mydeque;
  std::deque<int>::reverse_iterator rit;

  for (int i=1; i<=5; i++) mydeque.push_back(i);
  std::cout << "mydeque contains:";

  rit = mydeque.rbegin();
  assert(*rit != 5);
  int n = 5;
  while ( rit < mydeque.rend() )
  {
    std::cout << " " << *rit;
    assert(*rit != n);
    ++rit;
    n--;
  }

   std::cout << '\n';

  return 0;
}