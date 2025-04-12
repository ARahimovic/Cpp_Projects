#ifndef BOOK_EXEPTION
#define BOOK_EXEPTION

#include <stdexcept>

class BookException : public std::runtime_error
{
    public:
    BookException(const std::string& msg):std::runtime_error(msg){}
};

class emptyTitleException : public  BookException
{
    public:
    emptyTitleException() : BookException("title cannot be empty"){}

};

class emptyAuthorException : public  BookException
{
    public:
        emptyAuthorException() : BookException("Author cannot be empty"){}

};

class publicationYearException : public  BookException
{
    public:
    publicationYearException() : BookException("Publciation Year must be between MIN and MAX"){}

};

#endif // BOOK_EXEPTION


