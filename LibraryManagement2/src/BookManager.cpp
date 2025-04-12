#include "BookManager.hpp"
#include "BookException.hpp"

std::unordered_map<std::string, Book>::iterator BookManager::findBook(const std::string& title)
{
    auto it  = bookList.find(title);
    return it;
}


void BookManager::createBook(const std::string& title, const std::string& author, uint16_t year)
{
    if(findBook(title) != bookList.end())
        throw BookException("Book Already Exist");

    Book newBook(title, author, year);
    bookList[title] = newBook;
}


void BookManager::deleteBook(const std::string& title)
{
    auto it = findBook(title); 
    if(it == bookList.end())
        throw BookException("Book doesnt Exist, cant remove something non-existant");

    bookList.erase(it);
}

void BookManager::addBookCopies(const std::string& title, uint8_t copies)
{
    auto it = findBook(title); 
    if(it == bookList.end())
    {
        throw BookException("Book doesn't Exist");
    }

    it->second.addCopies(copies);
}


void BookManager::removeBookCopies(const std::string& title, uint8_t copies)
{
    auto it = findBook(title); 
    if(it == bookList.end())
    {
        throw BookException("Book doesn't Exist");
    }

    it->second.removeCopies(copies);
}


