#include "Vector.hpp"


MyVector::MyVector() = default;


MyVector::MyVector(size_t capacity, int repeatValue):
size_(capacity), capacity_(capacity), data_((capacity != 0) ? new int[capacity] : nullptr)
{
    std::fill_n(data_, capacity, repeatValue);
}

MyVector::MyVector(size_t capacity):MyVector(capacity, 0)
{
}

//initializer list constructor
MyVector::MyVector(std::initializer_list<int> values):capacity_(values.size()), size_(values.size()),data_( (capacity_ != 0)? new int[capacity_] : nullptr)
{
    std::copy(values.begin(), values.end(), data_);
}

//copy constructor
MyVector::MyVector(const MyVector& rhs):size_(rhs.size_),capacity_(rhs.capacity_),data_( (capacity_ != 0)? new int[capacity_] : nullptr)
{
    std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
}

//move constructor 
MyVector::MyVector(MyVector&& rhs) noexcept :size_(rhs.size_),capacity_(rhs.capacity_), data_(rhs.data_)
{
    rhs.data_ = nullptr;
    rhs.capacity_ = 0;
    rhs.size_ = 0;
}


size_t MyVector::size() const {   return size_; }

size_t MyVector::capacity() const {return capacity_; }

bool MyVector::empty() const { return size_ == 0; }

pointer MyVector::begin() {return data_;}
pointer MyVector::end() {return data_ + size_;}

MyVector::const_pointer MyVector::cbegin() const{return data_;}
MyVector::const_pointer MyVector::cend() const{return data_ + size_;}

int MyVector::front() const 
{
    if empty()
        throw std::out_of_range("front() on empty vector");

    return *data_;
}

int MyVector::back() const {
    if empty()
        throw std::out_of_range("back() on empty vector");

    return *(data_ + size_ - 1);}


void MyVector::push_back(int value)
{
    if(size_ == capacity_)
    {
        capacity_ = (capacity_ == 0)? 1 : capacity_ * 2;
        int* ptr = new int[capacity_];
        std::copy(data_, data_ + size_, ptr);
        delete[] data_;
        data_ = ptr;
    }
    data_[size_++] = value;
}


int MyVector::operator[](unsigned int index)
{
    return data_[index];
}

int MyVector::at(unsigned int index)
{
    if(index > size() - 1)
        throw std::out_of_range("at() index out of range");

    return data_[index];
}

MyVector::~MyVector()
{
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}



// 1. What are iterators in C++?
// Iterators are objects that allow traversal of containers (like arrays, vectors, lists) in C++. They act like generalized pointers and provide a way to access elements sequentially without exposing the underlying structure.

// 2. Difference between iterator and raw pointer:
// Raw pointers are basic memory addresses, while iterators are objects that may encapsulate pointers and provide additional functionality (like bounds checking, custom traversal, etc.). In many STL containers, iterators are implemented as pointers, but for complex containers (like list, map), they are custom classes.

// 3. How to convert raw pointer into an iterator:
// For containers like std::vector, you can use a raw pointer as an iterator. For custom containers, you may need to implement an iterator class that wraps the pointer. Example: std::vector<int>::iterator it = &vec[0];

// 4. How is end iterator implemented? Do we allocate size + 1 memory and leave the last one as unused?
// The end iterator points one past the last valid element. In most implementations, it does not require allocating extra memory; it is just a pointer to the position after the last element. No unused memory is allocated for the end iterator.


//difference between reserve abd resize() ?
//one change capacity , other change size