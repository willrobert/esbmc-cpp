// list::emplace_back
#include <iostream>
#include <list>
#include <cassert>

int main ()
{
  std::list<int>  mylist;

  mylist.emplace(mylist.end(), 20);
  mylist.emplace(mylist.end(), 30);
  mylist.emplace(mylist.begin(), 10);

  assert(*mylist.begin() == 10);
  assert(*(--mylist.end()) == 30);
  std::cout << "mylist contains:";
  for (auto& x: mylist)
    std::cout << " (" << x <<")";

  std::cout << std::endl;
  return 0;
}
