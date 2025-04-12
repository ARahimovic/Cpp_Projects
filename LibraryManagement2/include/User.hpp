#ifndef USER_HPP
#define USER_HPP
#include <vector>
#include "commonTypes.hpp"

class User
{
    public:
        User();
        User(const std::string& name, const Date& date);
        void borrowBook(const std::string& bookTitle);
        void returnBook(const std::string& bookTitle);
        const std::vector<std::string>& getBorrowedBooks() const;

    private:
        std::string name;
        Date birthDate;
        std::vector<std::string> borrowedBooksList {};
};

#endif // USER_HPP