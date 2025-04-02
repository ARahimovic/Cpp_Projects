#include "Book.hpp"
#include <iostream>

Book::Book(const std::string& t, const std::string& a, int y, uint16_t c):title(t),author(a),releaseYear(y),count(c){}
void Book::displayBookInfo() const
{
    std::cout << "Title : " <<title << ", Author : " << author << ", Year : " << releaseYear << ", Count : " << count << std::endl;
}
Book::Book(){}
std::string Book::getAuthor() const {return author; }
std::string Book::getTitle() const {return title; }
uint16_t Book::getReleaseYear() const {return releaseYear; }
void Book::increaseCount(uint8_t num = 1) {count += num; }
void Book::decreaseCount(uint8_t num = 1){ 
    if (count >= num)
        count -= num;
    else
        count = 0;
}

uint16_t Book::getCount() const {return count;}