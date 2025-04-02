#ifndef BOOK_HPP
#define BOOK_HPP

#include <cstdint>
#include <string>

class Book
{
    public:
        Book();
        Book(const std::string& t, const std::string&  a, int y, uint16_t count = 1);
        void displayBookInfo() const;
        std::string getAuthor() const;
        std::string getTitle() const;
        uint16_t getReleaseYear() const;
        uint16_t getCount() const; 
        void increaseCount(uint8_t num);
        void decreaseCount(uint8_t num);

    private:
        std::string title;
        std::string author;
        uint16_t releaseYear;
        uint16_t count;
};

#endif //BOOK_HPP