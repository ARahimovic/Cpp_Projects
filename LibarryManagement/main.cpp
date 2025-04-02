#include <iostream>
#include "BookManagement.hpp"
#include "Book.hpp"

void testAddBook(BookManagement& bm) {
    std::cout << "Test 1: Add a new book" << std::endl;
    Book book1("1984", "George Orwell", 1949);
    bm.addBook(book1);
    bm.displayAllBooks(); // Should display "1984" by George Orwell

    std::cout << "Test 2: Add a book with title and author only" << std::endl;
    bm.addBook("To Kill a Mockingbird", "Harper Lee", 1960);
    bm.displayAllBooks(); // Should display "1984" and "To Kill a Mockingbird"
}

void testUpdateBookCount(BookManagement& bm) {
    std::cout << "Test 3: Add the same book again and check count" << std::endl;
    bm.addBook("1984", "George Orwell", 1949); // Same book
    bm.displayAllBooks(); // Should show updated count for "1984"
}

void testRemoveBook(BookManagement& bm) {
    std::cout << "Test 4: Remove an existing book" << std::endl;
    bm.removeBook("1984");
    bm.displayAllBooks(); // "1984" should no longer appear

    std::cout << "Test 5: Remove a book that doesn't exist" << std::endl;
    bm.removeBook("Some Non-Existent Book");
    bm.displayAllBooks(); // Should not change anything, as the book doesn't exist
}

void testRemoveSpecificCount(BookManagement& bm) {
    std::cout << "Test 6: Remove a specific number of copies of a book" << std::endl;
    bm.removeBook("To Kill a Mockingbird", 1); // If more than 1 copy exists, count should decrease
    bm.displayAllBooks(); // "To Kill a Mockingbird" count should be updated
}

void testEdgeCases(BookManagement& bm) {
    std::cout << "Test 7: Add a book with an empty title" << std::endl;
    bm.addBook("", "No Author", 2020); // Should ideally handle this case gracefully
    bm.displayAllBooks(); // Should display an empty title book with "No Author"

    std::cout << "Test 8: Add a book with an empty author" << std::endl;
    bm.addBook("Untitled Book", "", 2020); // Should handle empty author gracefully
    bm.displayAllBooks(); // Should display "Untitled Book" with no author

    std::cout << "Test 9: Add a book with edge release year" << std::endl;
    bm.addBook("Future Book", "Author", 9999); // Test with the far future year
    bm.addBook("Past Book", "Author", 0); // Test with ancient year (0)
    bm.displayAllBooks(); // Should display books with edge years
}

void testRemoveAllInstances(BookManagement& bm) {
    std::cout << "Test 10: Remove all instances of a book, should delete it completely" << std::endl;
    bm.removeBook("To Kill a Mockingbird", 3); // If 3 copies exist, it should remove all
    bm.displayAllBooks(); // "To Kill a Mockingbird" should no longer appear
}

int main() {
    BookManagement bm;

    // Run each test
    testAddBook(bm);
    testUpdateBookCount(bm);
    testRemoveBook(bm);
    testRemoveSpecificCount(bm);
    testEdgeCases(bm);
    testRemoveAllInstances(bm);

    return 0;
}
