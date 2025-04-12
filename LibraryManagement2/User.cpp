#include "User.hpp"

User::User(const std::string& name, const Date& date):name(name), birthDate(date){}

void User::borrowBook(const std::string& bookTitle){ borrowedBooksList.push_back(bookTitle);}

void User::returnBook(const std::string& bookTitle)
{
    for(auto title : borrowedBooksList)
    {
        if(title == bookTitle)
        {
            borrowedBooksList.erase(bookTitle);
            break;
        }
    }
}
