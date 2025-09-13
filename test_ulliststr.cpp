#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  // Test 1: Push_back(), front(), back()
  ULListStr list;

  list.push_back("1");
  list.push_back("2");
  list.push_back("3");

  std::cout << "Push_back Test 1 ";
  std::cout << "Element at front: " << list.front() << "\n";
  std::cout << "Element at back: " << list.back() << "\n";


  // Test 2: Push_front(), front(), back()
  ULListStr list2;

  list2.push_front("4");
  list2.push_front("5");
  list2.push_front("6");

  std::cout << "Push_front Test 2 ";
  std::cout << "Element at front: " << list2.front() << "\n";
  std::cout << "Element at back: " << list2.back() << "\n";
  // Test 3: Pop_back(), Pop_front(), Push_back(), front(), back()
  ULListStr list3;

  list3.push_back("7");
  list3.push_back("8");
  list3.push_back("9");

  list3.pop_back();
  list3.pop_front();

  std::cout << "Pop_front/Pop_back Test 3 ";
  std::cout << "List size: " << list3.size() << "\n";
  std::cout << "Element at front: " << list3.front() << "\n";
  std::cout << "Element at back: " << list3.back() << "\n";
}
