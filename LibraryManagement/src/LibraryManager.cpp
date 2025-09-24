#include "LibraryManager.hpp"
#include "BookException.hpp"

void LibraryManager::createUser(const std::string& name, const Date& birthDate)
{
    userManager.createUser(name, birthDate);
}

void LibraryManager::removeUser(const std::string& name)
{
    userManager.removeUser(name);
}

void LibraryManager::addBook(const std::string& bookTitle, const std::string& author, uint16_t year)
{
    bookManager.createBook(bookTitle, author, year);
}

void LibraryManager::removeBook(const std::string& title)
{
    bookManager.deleteBook(title);
}

void LibraryManager::borrowBook(const std::string& userName, const std::string& bookTitle)
{
    //check if book exist
    if(!bookManager.bookExists(bookTitle))
        throw BookException("LibraryManager::borrowBook  : book does not exist, cannot borrow");

    //check if user exist
    if(!userManager.userExists(userName))
        throw BookException("LibraryManager::borrowBook  : user does not exist, cannot borrow");
    //call the bookManager borrow method
    bookManager.borrowBook(bookTitle);
    //call the userManager borrow method
    userManager.userBorrowBook(userName, bookTitle);
}

void LibraryManager::returnBook(const std::string& userName, const std::string& bookTitle)
{
     //check if book exist
    if(!bookManager.bookExists(bookTitle))
     throw BookException("LibraryManager::borrowBook  : book does not exist, cannot return book");

    //check if user exist
    if(!userManager.userExists(userName))
        throw BookException("LibraryManager::borrowBook  : user does not exist, cannot borrow");
    
    //call the bookManager return  method
    bookManager.returnBook(bookTitle);
    //call the userManager return method
    userManager.userReturnBook(userName, bookTitle);
}

