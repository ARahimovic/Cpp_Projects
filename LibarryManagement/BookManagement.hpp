#ifndef BOOK_MANAGEMENT_HPP
#define BOOK_MANAGEMENT_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include "Book.hpp"

using namespace std;


class BookManagement
{
    //it should have a list of all the books in the libary
    //the books should be dictionaries where each book has a title, author, descirption and release date
    //can have many copies of the same book
    //some copies might have been borrowed so decrease count, or returned increase count


    //we should have an empty unoredred map, key : bookTitle, book class
    
    public:
        BookManagement();
        void addBook(const std::string& title, const std::string& author, uint16_t year = 0000, uint16_t count = 1);
        void addBook(const Book& myBook);
        void removeBook(const std::string& title, uint8_t count = 1);
        Book findBook(const std::string& title);
        void removeAllBooks();
        void displayAllBooks() const;
        std::vector<Book> getAllBooks() const;
        std::vector<Book> getBooksByAuthor(const std::string& author) const;
        std::vector<Book> filterByYear(int year = 0, bool isGreater = true) const;
        std::vector<Book> multipleFilters(const std::string& author = "", int year = 0, bool isGreater=true) const;

    private:
        std::unordered_map<std::string, Book> bookList;

};

#endif //BOOK_MANAGEMENT_HPP