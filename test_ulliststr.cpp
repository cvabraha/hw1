#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;

  std::cout << "1. Testing basic pushes: " << std::endl;
  dat.push_back("apple");
  dat.push_back("banana");
  dat.push_front("zebra");
  dat.push_front("yak");

  std::cout << "List size: " << dat.size() << " (Expected: 4)" << std::endl;
  std::cout << "Front: " << dat.front() << " (Expected: yak)" << std::endl;
  std::cout << "Back: " << dat.back() << " (Expected: banana)" << std::endl;

  std::cout << "\n2. Testing get(): " << std::endl;

  for(size_t i = 0; i< dat.size(); i++){
    std::cout << dat.get(i) << " ";
  }

  std::cout << std::endl;

  std::cout << "\n3. Testing pops: ";
  dat.pop_back();
  dat.pop_front();

  std::cout << "\n4. Is list empty? " << (dat.empty() ? "Yes" : "No") << std::endl;

  std::cout << "\n5. Testing pops: ";
  dat.pop_back();
  dat.pop_front();

  for (int i = 1; i <= 15; i++) {
      dat.push_back(std::to_string(i));
  }

  std::cout << "List size after 15 push backs: " << dat.size() << " (Expected: 15)" << std::endl;

  return 0;


}
