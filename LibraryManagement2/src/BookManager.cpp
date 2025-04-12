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


