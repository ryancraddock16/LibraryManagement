//
// Created by Joseph Campione on 11/22/24.
//

#include "Inventory.h"
#include "LibraryHash.h"
#include <iostream>


/**
 * @brief Constructs an Inventory with a specified size.
 *
 * @param size The size of the inventory (number of books).
 */
Inventory::Inventory(int size) {
    books = new Book*[size];
    this->size = size;
}

/**
 * @brief Default constructor. Initializes an inventory with a default size of 10000 books.
 */
Inventory::Inventory() {
    books = new Book*[10000];
    this->size = 10000;
}

/**
 * @brief Destructor. Frees dynamically allocated memory for the inventory books.
 */
Inventory::~Inventory() {
    delete[] books;
}

/**
 * @brief Adds a book to the inventory.
 *
 * Uses the hash function to determine the correct index for storing the book.
 *
 * @param b Pointer to the Book object to be added.
 */
void Inventory::addBook(Book *b) const {
    books[LibraryHash::HashBook(b, size)] = b;
}

/**
 * @brief Removes a book from the inventory.
 *
 * Sets the book's entry to `nullptr` based on its hash index.
 *
 * @param b Pointer to the Book object to be removed.
 */
void Inventory::removeBook(const Book *b) const {
    books[LibraryHash::HashBook(b, size)] = nullptr;
}

/**
 * @brief Finds a book in the inventory by its ISBN.
 *
 * Converts the ISBN string to a long long value and calls the other version of this function.
 *
 * @param ISBN The ISBN of the book as a string.
 * @return Pointer to the Book object, or nullptr if the book is not found.
 */
Book* Inventory::findBookByISBN(string ISBN) const {
    long long ISBNnum = LibraryHash::formatISBN(ISBN);
    return findBookByISBN(ISBNnum);
}

/**
 * @brief Checks if a book is available in the inventory by its ISBN.
 *
 * Converts the ISBN string to a long long value and checks availability.
 *
 * @param ISBN The ISBN of the book as a string.
 * @return True if the book is available, false otherwise.
 */
bool Inventory::isBookAvailable(string ISBN) const {
    long long ISBNnum = LibraryHash::formatISBN(ISBN);
    return isBookAvailable(ISBNnum);
}

/**
 * @brief Lists all available books in the inventory.
 *
 * Iterates over the inventory and prints information about books that are available.
 */
void Inventory::listAvailableBooks() const {
    for (int i = 0; i < size; i++) {
        if (books[i] != nullptr && books[i]->isAvailable()) {
            cout << books[i]->getInfo() << endl;
        }
    }
}

/**
 * @brief Lists all checked-out books in the inventory.
 *
 * Iterates over the inventory and prints information about books that are not available.
 */
void Inventory::listCheckedOutBooks() const {
    for (int i = 0; i < size; i++) {
        if (books[i] != nullptr && !books[i]->isAvailable()) {
            cout << books[i]->getInfo() << endl;
        }
    }
}

/**
 * @brief Updates the availability status of a book.
 *
 * Toggles the availability of the given book.
 *
 * @param b Pointer to the Book object whose availability will be updated.
 * @return The new availability status of the book.
 */
bool Inventory::updateBookAvailablity(Book* b) {
    b->setIsAvailable(!b->isAvailable());
    return b->isAvailable();
}

/**
 * @brief Counts the total number of books in the inventory.
 *
 * Iterates through the inventory and counts the number of non-null entries.
 *
 * @return The total number of books in the inventory.
 */
long Inventory::countTotalBooks() const {
    long count = 0;
    for (int i = 0; i < size; i++) {
        if (books[i] != nullptr) {
            count++;
        }
    }
    return count;
}

/**
 * @brief Prints all books in the inventory along with their index.
 *
 * Iterates through the inventory and prints information about each non-null book.
 */
void Inventory::print() const {
    for (int i = 0; i < size; i++) {
        if (books[i] != nullptr) {
            cout << "Index : " << i << " " << books[i]->getInfo() << endl;
        }
    }
}

/**
 * @brief Checks if a book is available by its ISBN.
 *
 * Uses the ISBN hash to locate the book and check its availability.
 *
 * @param ISBN The ISBN of the book.
 * @return True if the book is available, false otherwise.
 */
bool Inventory::isBookAvailable(const long long int ISBN) const {
    return books[LibraryHash::ISBNToHash(ISBN, size)]->isAvailable();
}

/**
 * @brief Finds a book in the inventory by its ISBN.
 *
 * Uses the ISBN hash to locate and return the book.
 *
 * @param ISBN The ISBN of the book.
 * @return Pointer to the Book object, or nullptr if not found.
 */
Book *Inventory::findBookByISBN(const long long int ISBN) const {
    return books[LibraryHash::ISBNToHash(ISBN, size)];
}

/**
 * @brief Finds a book in the inventory by its title.
 *
 * Searches through the inventory to find the first book with a matching title.
 *
 * @param title The title of the book.
 * @return Pointer to the Book object, or nullptr if not found.
 */
Book *Inventory::findBookByTitle(const string& title) const {
    for (int i = 0; i < size; i++) {
        if (books[i] != nullptr && books[i]->getTitle() == title) {
            return books[i];
        }
    }
    return nullptr;
}
