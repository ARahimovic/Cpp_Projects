#ifndef BOOK_EXCEPTIONS_HPP
#define BOOK_EXCEPTIONS_HPP

class BookException : public std::runtime_error 
{
    public:
        BookException(const std::string& msg) : std::runtime_error(msg){}
};

class EmptyAuthorException : public BookException
{
    public:
        EmptyAuthorException():BookException("Author name cannot be empty"){}
};

class EmptyTitleException : public BookException
{
    public:
    EmptyTitleException() : BookException("title cannot be empty"){}
};

class BookNotFoundException : public BookException
{
    public:
        BookNotFoundException(): BookException("Book not found"){}
};


#endif // BOOK_EXCEPTIONS_HPP