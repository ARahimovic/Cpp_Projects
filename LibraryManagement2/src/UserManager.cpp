#include "UserManager.hpp"
#include "BookException.hpp"

void UserManager::createUser(const std::string& name, const Date& birthDate)
{
    if(name.empty())
        throw BookException("UserManager::createUser(const std::string& name, const Date& birthDate) , user name cannot be empty");

    if(!birthDate.isDateValid())
        throw BookException("UserManager::createUser(const std::string& name, const Date& birthDate) , birth Date not valid");
    
    auto it = userMap.find(name);
    if(it != userMap.end())
        throw BookException("UserManager::createUser(const std::string& name, const Date& birthDate) , User already exists"); 
    
    User newUser(name, birthDate);
    userMap[name] = newUser;
}

void UserManager::removeUser(const std::string& name)
{
    if(name.empty())
        throw BookException("UserManager::removeUser(const std::string& name) , user name cannot be empty");

    auto it = userMap.find(name);
    if(it == userMap.end())
        throw BookException("UserManager::createUser(const std::string& name) , User does not exists , cant remove"); 
    
   userMap.erase(it);
}


User& UserManager::getUser(const std::string& name)
{
    if(name.empty())
        throw BookException("UserManager::getUser(const std::string& name) , user name cannot be empty");

    auto it = userMap.find(name);
    if(it == userMap.end())
        throw BookException("UserManager::getUser(const std::string& name) , User does not exists"); 
    
    return it->second;
}

bool UserManager::userExists(const std::string& name) const
{
    if(name.empty())
        throw BookException("UserManager::getUser(const std::string& name) , user name cannot be empty");

    return userMap.find(name)!= userMap.end();
}

