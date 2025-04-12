#include "Book.hpp"
#include "BookException.hpp"
#include <iostream>

Book::Book():title("init"), author("init"), publicationYear(MIN_PUBLICATION_YEAR){}

Book::Book(const std::string& title, const std::string& author, uint16_t year)
{
    if(title.empty())
        throw emptyTitleException();
    if(author.empty())
        throw emptyAuthorException();
    if(year < MIN_PUBLICATION_YEAR || year > MAX_PUBLICATION_YEAR)
        throw publicationYearException();

    this->title = title;
    this->author = author;
    this->publicationYear = year;
    this->totalCopies = 1;
    this->availableCopies = 1;
}

std::string Book::getTitle() const {return title;}
std::string Book::getAuthor() const {return author;}
uint16_t Book::getPublicationYear() const {return publicationYear;}
bool Book::isBookAvailable() const { return availableCopies != 0;}

void Book::addCopies(uint16_t number)
{
    if(number == 0)
        throw BookException("number of copies must be a positive non-zero number");
    
    totalCopies += number;
    availableCopies += number;
}

void Book::removeCopies(uint16_t number)
{
    if(number == 0)
        throw BookException("number of copies must be a positive non-zero number");
    
    if(number > availableCopies)
        throw BookException("Cannot remove more copies than available");

    
    totalCopies -= number;
    availableCopies -= number;
}

void Book::borrowBook()
{
    if(availableCopies == 0)
        throw BookException("No Copies available to borrow");

    availableCopies --;
}

void Book::returnBook()
{
    if(availableCopies < totalCopies )
        availableCopies++;
    else
        throw BookException("All Copies are already returned");
}

uint16_t Book::getTotalCopies() const { return totalCopies;}
uint16_t Book::getAvailableCopies() const {return availableCopies; }

void Book::displayBook() const
{
    std::cout << "title : " << title << ", Author : " << author << "publicationYear : " << publicationYear;
}