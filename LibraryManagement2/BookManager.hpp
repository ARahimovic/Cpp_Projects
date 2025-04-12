#ifndef BOOK_MANAGER_HPP
#define BOOK_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <cstdint>

#include "Book.hpp"

class BookManager
{
    public:
        BookManager() = default;
        std::unordered_map<std::string, Book>::iterator findBook(const std::string& title);
        void createBook(const std::string& title, const std::string& author, uint16_t year);
        void deleteBook(const std::string& title);
        void addBookCopies(const std::string& title, uint8_t copies);
        void removeBookCopies(const std::string& title, uint8_t copies);
        void listAllBooks();

    private:
        std::unordered_map<std::string, Book> bookList;
};

#endif // BOOK_MANAGER_HPP