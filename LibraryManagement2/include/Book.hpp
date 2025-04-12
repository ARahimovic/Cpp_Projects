#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
#include <cstdint>

constexpr uint16_t MIN_PUBLICATION_YEAR = 850;
constexpr uint16_t MAX_PUBLICATION_YEAR = 2025;

class Book
{
    public:
        Book();
        Book(const std::string& title, const std::string& author, uint16_t year);
        std::string getTitle() const;
        std::string getAuthor() const;
        uint16_t getPublicationYear() const;
        bool isBookAvailable() const;
        void addCopies(uint16_t number);
        void removeCopies(uint16_t number);
        void borrowBook();
        void returnBook();
        uint16_t getTotalCopies() const;
        uint16_t getAvailableCopies() const;
        void displayBook() const;

    private :
        std::string title;
        std::string author;
        uint16_t publicationYear;
        uint16_t totalCopies;
        uint16_t availableCopies;

};


#endif //BOOK_HPP