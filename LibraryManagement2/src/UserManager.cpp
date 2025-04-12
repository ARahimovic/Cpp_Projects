#include "UserManager.hpp"
#include "BookException.hpp"

void UserManager::createUser(const std::string& name, const Date& birthDate)
{
    if(name.empty())
        throw BookException("UserManager::createUser(const std::string& name, const Date& birthDate) , user name cannot be empty");

    if(!birthDate.isDateValid())
        throw BookException("UserManager::createUser(const std::string& name, const Date& birthDate) , birth Date not valid");
    
    auto it = usersMap.find(name);
    if(it != usersMap.end())
        throw BookException("UserManager::createUser(const std::string& name, const Date& birthDate) , User already exists"); 
    
    usersMap.emplace(name, User(name, birthDate));
}

void UserManager::removeUser(const std::string& name)
{
    if(name.empty())
        throw BookException("UserManager::removeUser(const std::string& name) , user name cannot be empty");

    auto it = usersMap.find(name);
    if(it == usersMap.end())
        throw BookException("UserManager::removeUser(const std::string& name) , User does not exists , cant remove"); 
    
   usersMap.erase(it);
}


User& UserManager::getUser(const std::string& name)
{
    if(name.empty())
        throw BookException("UserManager::getUser(const std::string& name) , user name cannot be empty");

    auto it = usersMap.find(name);
    if(it == usersMap.end())
        throw BookException("UserManager::getUser(const std::string& name) , User does not exists"); 
    
    return it->second;
}

bool UserManager::userExists(const std::string& name) const
{
    if(name.empty())
        throw BookException("UserManager::userExists(const std::string& name) , user name cannot be empty");

    return usersMap.find(name)!= usersMap.end();
}

void UserManager::userBorrowBook(const std::string& name, const std::string& bookTitle)
{
    if(name.empty())
        throw BookException("UserManager::userBorrowBook , user name cannot be empty");

    if(bookTitle.empty())
        throw BookException("UserManager::userBorrowBook , bookTitle cannot be empty");

    auto it = usersMap.find(name);
    if(it == usersMap.end())
        throw BookException("UserManager::userBorrowBook() , User does not exists"); 

    it->second.borrowBook(bookTitle);
}


void UserManager::userReturnBook(const std::string& name, const std::string& bookTitle)
{
    if(name.empty())
        throw BookException("UserManager::userReturnBook , user name cannot be empty");

    if(bookTitle.empty())
        throw BookException("UserManager::userReturnBook , bookTitle cannot be empty");

    auto it = usersMap.find(name);
    if(it == usersMap.end())
        throw BookException("UserManager::userReturnBook() , User does not exists"); 

    it->second.returnBook(bookTitle);
}


void UserManager::displayUser(const std::string& name) const
{
    if(name.empty())
        throw BookException("UserManager::displayUser , user name cannot be empty");

    auto it = usersMap.find(name);
    if(it == usersMap.end())
        throw BookException("UserManager::displayUser() , User does not exists");
        
    it->second.displayUser();
}


void UserManager::displayAllUsers()const
{
   for(const auto& user : usersMap)
   {
        user.second.displayUser();
   }
}



