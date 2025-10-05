#include "MyClass.h"


int MyClass::getPayload() const{ return payload; }

std::ostream& operator<<(std::ostream& os, const MyClass& obj)
{
    os << "{index = " << obj.id << ", payload = " << obj.payload << "}";
    return os;
}

MyClass::MyClass(int payload):id(counter++),payload(payload)
{
    std::cout << "MyClass::MyClass(int: " << payload <<")" << *this << std::endl;    
}

MyClass::MyClass(const MyClass& rhs):id(counter++),payload(rhs.payload)
{
    std::cout<< "MyClass::MyClass(const MyClass&: " << rhs <<")" << *this << std::endl; 
}

MyClass::MyClass(MyClass&& rhs):id(counter++), payload(rhs.payload)
{
    std::cout<< "MyClass::MyClass(MyClass&&: " << rhs <<")" << *this << std::endl;

    rhs.payload = defaultPayload;
}

MyClass& MyClass::operator=(const MyClass& rhs)
{
    std::cout << "MyClass::operator =(const MyClass&: " << rhs << ")" << *this << std::endl;
    
    payload = rhs.payload;
    return *this;
}


MyClass& MyClass::operator=(MyClass&& rhs)
{
    std::cout << "MyClass::operator =(MyClass&&: " << rhs << ")" << *this << std::endl;
    
    payload = rhs.payload;
    rhs.payload = defaultPayload;
    return *this;
}


MyClass::~MyClass() {
  std::cout  << "MyClass::~MyClass():" << *this << '\n';
}


unsigned int MyClass::counter = 0;