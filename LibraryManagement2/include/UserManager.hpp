#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <unordered_map>
#include <string>
#include "User.hpp"

class UserManager
{
    public:
        UserManager() = default;
        void createUser(const std::string& name, const Date& birthDate);
        void removeUser(const std::string& name);
        User& getUser(const std::string& name);
        bool userExists(const std::string& name) const;
        void userBorrowBook(const std::string& name, const std::string& bookTitle);
        void userReturnBook(const std::string& name, const std::string& bookTitle);
        void displayUser(const std::string& name) const;
        void displayAllUsers() const;
    private:
        std::unordered_map<std::string, User> usersMap {};
};


#endif //USER_MANAGER_HPP