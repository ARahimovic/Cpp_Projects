#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <cstddef>
#include <initializer_list>

class MyVector
{
    private:
        int *data_ {};
        size_t size_ {};
        size_t capacity_ {};

        //helper method for copy-swap idiom
        void swap(Vector rhs) noexcept;
        
    public:
    
    MyVector(); 
    MyVector(std::initializer_list<int> values);
    MyVector(size_t capacity);
    MyVector(size_t capacity, int repeatValue);
    MyVector(const MyVector& rhs);
    MyVector(MyVector&& rhs) noexcept;
    MyVector& operator=(const MyVector& rhs);
    MyVector& operator=(MyVector&& rhs) noexcept;



    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    void resize(size_t size);
    void reserve(size_t size);
    void insert(int value, int index);
    void push_back(int value);
    
    using value_type = int;
    using pointer = int*;
    using const_pointer = const int*;  
    using reference = int&;
    using const_reference = const int&;

    pointer begin();
    pointer end();
    const_pointer cbegin();
    const_pointer cend();

    int front() const;
    int back() const;
    int at(unsigned int index) const;
    int operator[](unsigned int index) const;

    ~MyVector();
};


#endif // MY_VECTOR_HPP