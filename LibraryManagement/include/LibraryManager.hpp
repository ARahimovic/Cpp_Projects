#ifndef LIBRARY_MANAGER_HPP
#define LIBRARY_MANAGER_HPP

#include "BookManager.hpp"
#include "UserManager.hpp"

class LibraryManager
{
    public:
    LibraryManager() = default;
    void createUser(const std::string& name, const Date& birthDate);
    void removeUser(const std::string& name);
    void addBook(const std::string& bookTitle, const std::string& author, uint16_t year);
    void removeBook(const std::string& bookTitle);
    void borrowBook(const std::string& userName, const std::string& bookTitle);
    void returnBook(const std::string& userName, const std::string& bookTitle);
    

    private:
    BookManager bookManager;
    UserManager userManager;

};

#endif // LIBRARY_MANAGER_HPP