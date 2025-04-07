#include "BookManagement.hpp"
#include "BookExceptions.hpp"

BookManagement::BookManagement():bookList(){ }


Book BookManagement::findBook(const std::string& title)
{
    if(title.empty())
        throw EmptyTitleException();

    try
    {
        return bookList.at(title);
    }
    catch(const std::out_of_range&)
    {
        throw BookNotFoundException();
    }

    //valid implementation but above is better
    // auto it = bookList.find(title);
    // if(it == bookList.end())
    // {
    //     throw BookNotFoundException();
    //     return nullptr;
    // }
    // return it.second;

}

void BookManagement::addBook(const Book& myBook)
{  
    auto it = bookList.find(myBook.getTitle());
    //book not found
    if(it == bookList.end())
    {
        //add the book to the list
        bookList[myBook.getTitle()] = myBook;

    }
    //if book already exist
    else
    {
        it->second.increaseCount(myBook.getCount());
    }

}

void BookManagement::addBook(const std::string& title, const std::string& author, uint16_t year , uint16_t count)
{
    auto it = bookList.find(title);
    if(it == bookList.end())
    {
        //if book not found, create a new book
        Book newBook(title, author, year, count);
        bookList[title] = newBook;
    }
    else
    {
        //if book already exist, increase the count
        bookList[title].increaseCount(count);
    }
}


void BookManagement::removeBook(const std::string& title, uint8_t count)
{
    auto it = bookList.find(title);
    if(it == bookList.end())
    {
        std::cout << "remove Book : book not found" << std::endl;
    }
    else // book found
    {
        //remove count number of copies from the map
        it->second.decreaseCount(count);
        //if after removing the book , we have zero copies of it, we remove the book entirely
        if (it->second.getCount() == 0)
            bookList.erase(it);
    }
}

std::vector<Book> BookManagement::getAllBooks() const
{
    std::vector<Book> books = {};

    for(const auto& book : bookList)
    {
        books.push_back(book.second);
    }

    return books;
}

void BookManagement::displayAllBooks() const
{
    for(const auto& book : bookList)
    {
        book.second.displayBookInfo();
        std::cout << std::endl;
    }
}


std::vector<Book> BookManagement::getBooksByAuthor(const std::string& author) const
{
    if(author.empty())
    {
        throw EmptyAuthorException();
    }
    std::vector<Book> authorBooks = {};
    for(const auto& book : bookList)
    {
        if(book.second.getAuthor() == author)
        {
            authorBooks.push_back(book.second);
        }
    }

    return authorBooks;
}

std::vector<Book> BookManagement::filterByYear(int year, bool isGreater) const
{
    std::vector<Book> books = {};
    for(const auto& book : bookList)
    {
        if( (isGreater && book.second.getReleaseYear() >= year) || ( !isGreater && book.second.getReleaseYear() <= year))
            books.push_back(book.second);
        // if(isGreater)
        // {
        //     if(book.second.getReleaseYear() >= year)
        //         books.push_back(book);
            
        // }
        // else
        // {
        //     if(book.second.getReleaseYear() <= year)
        //         books.push_back(book);
        // }
    }

    return books;
}

std::vector<Book> BookManagement::multipleFilters(const std::string& author, int year, bool isGreater) const
{   
    std::vector<Book> books = {};

    //no filter applied
    if(author.empty() && year == 0)
        return this->getAllBooks();

    //author empty
    else if (author.empty() && year != 0)
    {
        return this->filterByYear(year, isGreater);
    }
    else if (year == 0 && !author.empty())
    {
        return this->getBooksByAuthor(author);
    }

    //use both filters
    for(const auto& book : bookList)
    {
        if (book.second.getAuthor() == author)
        {
            if ((book.second.getReleaseYear() >= year && isGreater) || (book.second.getReleaseYear() <= year && !isGreater))
                books.push_back(book.second);
        }
        
    }

    return books;
}



