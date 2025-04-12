#include "User.hpp"
#include "BookException.hpp"
#include <algorithm>


User::User():name("Unvalid"),birthDate(Date()){}
User::User(const std::string& name, const Date& date):name(name), birthDate(date){}

void User::borrowBook(const std::string& bookTitle)
{
    if(bookTitle.empty())
        throw BookException("User::borrowBook(const std::string& bookTitle) : bookTitle cannot be empty");

    auto it = std::find(borrowedBooksList.begin(), borrowedBooksList.end(), bookTitle);
    
    if(it != borrowedBooksList.end())
    {
        throw BookException("User::borrowBook(const std::string& bookTitle) : book already in borrowed List, cant borrow again");
    } 

    borrowedBooksList.push_back(bookTitle);
}

void User::returnBook(const std::string& bookTitle)
{
    if(bookTitle.empty())
        throw BookException("User::returnBook(const std::string& bookTitle) : bookTitle cannot be empty");


    //find the book 
    auto it = std::find(borrowedBooksList.begin(), borrowedBooksList.end(), bookTitle);

    if(it == borrowedBooksList.end())
    {
        throw BookException("User::returnBook(const std::string& bookTitle) : bookTitle cannot be found in borrowedBookList");
    }
    else
    {
        borrowedBooksList.erase(it);
    }

}

const std::vector<std::string>& User::getBorrowedBooks() const
{
    return borrowedBooksList;
}

