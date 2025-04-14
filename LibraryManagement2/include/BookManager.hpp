#ifndef BOOK_MANAGER_HPP
#define BOOK_MANAGER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>

#include "Book.hpp"

class BookManager
{
    public:
        BookManager() = default;
        std::unordered_map<std::string, Book>::iterator findBook(const std::string& title);
        bool bookExists(const std::string& title);
        void createBook(const std::string& title, const std::string& author, uint16_t year);
        void deleteBook(const std::string& title);
        void addBookCopies(const std::string& title, uint8_t copies);
        void removeBookCopies(const std::string& title, uint8_t copies);
        void borrowBook(const std::string& title);
        void returnBook(const std::string& title);
        void displayBook(const std::string& title) const;
        void displayAllBooks() const;
        Book& getBook(const std::string& title);
        std::vector<std::string> getAllBooksTitles() const;
        std::vector<const Book*> getAllBooks() const;
        std::vector<const Book*> searchByAuthor(const std::string& author) const;
        std::vector<const Book*> searchByYear(uint16_t year) const;

        /**
         * @brief Retrieves a list of all books that currently have at least one borrowed copy.
         *
         * This method scans through the entire book list and collects pointers to books
         * where the number of available copies is less than the total number of copies,
         * indicating that one or more copies are currently borrowed.
         *
         * @return std::vector<const Book*> A vector of constant pointers to borrowed books.
         *         The caller can read book information but cannot modify the books.
         */
        std::vector<const Book*> getBorrowedBooks() const;
        
        /**
         * @brief Returns the total number of book copies available in the library.
         * 
         * This includes all copies of all books (e.g., 3 copies of "Book A" + 2 copies of "Book B" = 5 total).
         * 
         * @return Total number of book copies.
         */
        size_t getTotalBookCount() const;
        
        
        /**
         * @brief Returns the count of unique book titles in the library.
         * 
         * This does not consider the number of copies per book, just how many different titles exist.
         * 
         * @return Number of unique books.
         */  
        size_t getUniqueBookCount() const;         


    private:
        std::unordered_map<std::string, Book> bookList;
};

#endif // BOOK_MANAGER_HPP