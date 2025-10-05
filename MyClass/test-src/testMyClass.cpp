#include "MyClass.h"

int main() {
  
  MyClass a(10);
  MyClass b(20);
  MyClass c = a;            // Copy constructor
  MyClass d = std::move(b); // Move constructor
  a = d;                    // Copy assignment
  b = std::move(c);         // Move assignment
  return 0;
}
