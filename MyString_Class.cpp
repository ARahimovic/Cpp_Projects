/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string.h>

class MyString
{
    public:
    
    MyString():data(nullptr),size(0){}
    
    MyString(const char* str)
    {
        size = strlen(str) + 1;
        data = new char[size];
        strncpy(data, str, size);
    }
    //copy constructor 
    MyString(const MyString& other)
    {
        if(other.data != nullptr)
        {
            size = other.size;
            data = new char[size];
            strncpy(data, other.data, size);
        }
    }

    //Move Constructor 
    MyString(MyString&& other)
    {
        size = other.size;
        data = other.data;

        other.data = nullptr;
        other.size = 0;
    }

    //Assignement operator 
    MyString& operator=(const MyString &other)
    {
        if(this != &other)
        {
            delete[] data;
            if(other.data != nullptr)
            {
                size = other.size;
                data = new char[size];
                strncpy(data, other.data, size);
            }
        }

        return *this;
    }

    //move assignement operator
    MyString& operator=(MyString&& other)
    {
        if(this != &other)
        {
            delete [] data;
            size = other.size;
            data = other.data;

            other.size = 0;
            other.data = nullptr;

        }
    }
    
    void Print()
    {
        if(data == nullptr)
            std::cout << "Empty String" << std::endl;
        else
            std::cout << this->data << std::endl;
    }

    private:
    char *data = nullptr;
    int size = 0;



};
int main()
{
    MyString s1("Rahimovic is Awsome");//normal construcot
    std::cout << "printing S1" << std::endl;
    s1.Print();
    
    MyString s2 = s1; // copy Constructor
    std::cout << "printing S2" << std::endl;
    s2.Print();
    
    
    MyString s3 = "Third string"; // implicit conversion, normal consutrcotr 
    std::cout << "printing S3" << std::endl;
    s3.Print();
    
    MyString s4 ;
    std::cout << "Assigning s3 to s4 " << std::endl;
    s4 = s3; // assignement opreator 
    s4.Print();
    
    s3 = std::move(s1); //Move assignement operator
    std::cout << "moving s1 to s3 " << std::endl;
    s3.Print();
    s1.Print();
    
    
    std::cout << "moving s2 to s5 " << std::endl;
    MyString s5 = std::move(s2); //move Constructor
    s5.Print();
    s2.Print();
    
    
    
    
    
    

    return 0;
}