#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <iostream>

class MyClass
{
    public:
        static unsigned int counter;
        static int defaultPayload;

        MyClass(int payload = defaultPayload);
        MyClass(const MyClass& rhs);
        MyClass(MyClass&& rhs);
        MyClass& operator=(const MyClass& rhs);
        MyClass& operator=(MyClass&& rhs);
        ~MyClass();
        int getPayload() const;

friend std::ostream& operator<<(std::ostream& os, const MyClass& obj);

    private:
        unsigned int id;
        int payload;
};

#endif