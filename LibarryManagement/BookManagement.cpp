#include "BookManagement.hpp"

BookManagement::BookManagement():bookList(){ }

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

void BookManagement::displayAllBooks()
{
    for(const auto& book : bookList)
    {
        book.second.displayBookInfo();
        std::cout << std::endl;
    }
}

