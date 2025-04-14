#include "BookManager.hpp"
#include "BookException.hpp"
#include <format>

std::unordered_map<std::string, Book>::iterator BookManager::findBook(const std::string& title)
{
    auto it  = bookList.find(title);
    return it;
}

bool BookManager::bookExists(const std::string& title)
{
    return findBook(title) != bookList.end();
}

void BookManager::createBook(const std::string& title, const std::string& author, uint16_t year)
{
    if(!bookExists(title))
        throw BookException("Book Already Exist");

    bookList.emplace(title, Book(title, author, year));
}


void BookManager::deleteBook(const std::string& title)
{
    auto it = findBook(title); 
    if(it == bookList.end())
        throw BookException("Book doesnt Exist, cant remove something non-existant");

    //some books are borrowed, cannot delete 
    if(it->second.getAvailableCopies() != it->second.getTotalCopies())
        throw BookException(std::format("Cannot delete book, {} copy/copies still borrowed", 
            it->second.getTotalCopies() - it->second.getAvailableCopies()));
    
    bookList.erase(it);
}

void BookManager::addBookCopies(const std::string& title, uint8_t copies)
{
    
    if(!bookExists(title))
    {
        throw BookException("Book doesn't Exist");
    }

    bookList[title].addCopies(copies);
}


void BookManager::removeBookCopies(const std::string& title, uint8_t copies)
{
    if(!bookExists(title))
    {
        throw BookException("Book doesn't Exist");
    }

    bookList[title].removeCopies(copies);
}


void BookManager::borrowBook(const std::string& title)
{
    if(!bookExists(title))
    {
        throw BookException("Book doesn't Exist");
    }

    bookList[title].borrowBook();
}

void BookManager::returnBook(const std::string& title)
{
    if(!bookExists(title))
    {
        throw BookException("Book doesn't Exist");
    }

    bookList[title].returnBook();
}

Book& BookManager::getBook(const std::string& title)
{
    auto it = findBook(title); 
    if(it == bookList.end())
    {
        throw BookException("Book doesn't Exist");
    }
    return it->second;    
}

void BookManager::displayBook(const std::string& title) const
{
    auto it = bookList.find(title);
    if(it == bookList.end())
    {
        throw BookException("Book doesn't Exist");
    }

    return it->second.displayBook();
}

void BookManager::displayAllBooks() const
{
    for(const auto& book : bookList)
    {
        book.second.displayBook();
    }
}


std::vector<std::string> BookManager::getAllBooksTitles() const
{
    std::vector<std::string> bookTitles;
    bookTitles.reserve(bookList.size());

    //a more modern syntax
    for(const auto& [title, _] : bookList)
        bookTitles.push_back(title);
    
    // for(const auto& book : bookList)
    //     bookTitles.push_back(book.first);

    return bookTitles;
}

std::vector<const Book*> BookManager::getAllBooks() const
{
    std::vector<const Book*> books;
    books.reserve(bookList.size());

    for(const auto& [_ , book] : bookList)
        books.push_back(&book);

    return books;
}


std::vector<const Book*> BookManager::searchByAuthor(const std::string& author) const
{
    std::vector<const Book*> booksByAuthor;
    booksByAuthor.reserve(bookList.size());


    if(author.empty())
        throw emptyAuthorException();

    for(const auto& [_, book] : bookList)
    {
        if(book.getAuthor() == author)
        booksByAuthor.push_back(&book);
    }   


    return booksByAuthor;
}


std::vector<const Book*> BookManager::searchByYear(uint16_t year) const
{
    std::vector<const Book*> booksByYear;
    booksByYear.reserve(bookList.size());


    for(const auto& [_, book] : bookList)
    {
        if(book.getPublicationYear() == year)
            booksByYear.push_back(&book);
    }   


    return booksByYear;
}

size_t BookManager::getTotalBookCount() const
{
    size_t total = 0;
    for(const auto& [_, book] : bookList)
        total += book.getTotalCopies();
    
        return total;       
}

size_t BookManager::getUniqueBookCount() const
{
    return bookList.size();
}


std::vector<const Book*> BookManager::getBorrowedBooks() const
{
    std::vector<const Book*> borrowedBooks;
    for(const auto& [_ , book] : bookList)
    {
        if(book.getAvailableCopies() < book.getTotalCopies())
            borrowedBooks.push_back(&book);
    }

    return borrowedBooks;
}
