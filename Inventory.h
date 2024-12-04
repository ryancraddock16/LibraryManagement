//
// Created by Joseph Campione on 11/22/24.
//

#ifndef LIBRARYMANAGEMENT_INVENTORY_H
#define LIBRARYMANAGEMENT_INVENTORY_H

#include <string>
#include "Book.h"
#include "LibraryHash.h"

using namespace std;

/**
 * @class Inventory
 * @brief Manages a collection of books within the library's system.
 *
 * The `Inventory` class handles the storage, retrieval, and management of books in a library.
 * It supports operations such as adding, removing, searching for books by title or ISBN, checking
 * availability, listing available or checked-out books, and updating book statuses. The inventory uses
 * hashing to store and locate books efficiently.
 */
class Inventory {
public:
    /**
     * @brief Constructs an Inventory with a specified size.
     *
     * @param size The size of the inventory (number of books).
     */
    Inventory(int size);

    /**
     * @brief Default constructor. Initializes an inventory with a default size of 10000 books.
     */
    Inventory();

    /**
     * @brief Destructor. Frees dynamically allocated memory for the inventory books.
     */
    ~Inventory();

    /**
     * @brief Adds a book to the inventory.
     *
     * Uses the hash function to determine the correct index for storing the book.
     *
     * @param b Pointer to the Book object to be added.
     */
    void addBook(Book* b) const;

    /**
     * @brief Removes a book from the inventory.
     *
     * Sets the book's entry to `nullptr` based on its hash index.
     *
     * @param b Pointer to the Book object to be removed.
     */
    void removeBook(const Book* b) const;

    /**
     * @brief Finds a book in the inventory by its ISBN.
     *
     * Converts the ISBN string to a long long value and calls the other version of this function.
     *
     * @param ISBN The ISBN of the book as a string.
     * @return Pointer to the Book object, or nullptr if the book is not found.
     */
    Book* findBookByISBN(string ISBN) const;

    /**
     * @brief Checks if a book is available in the inventory by its ISBN.
     *
     * Converts the ISBN string to a long long value and checks availability.
     *
     * @param ISBN The ISBN of the book as a string.
     * @return True if the book is available, false otherwise.
     */
    bool isBookAvailable(string ISBN) const;

    /**
     * @brief Lists all available books in the inventory.
     *
     * Iterates over the inventory and prints information about books that are available.
     */
    void listAvailableBooks() const;

    /**
     * @brief Lists all checked-out books in the inventory.
     *
     * Iterates over the inventory and prints information about books that are not available.
     */
    void listCheckedOutBooks() const;

    /**
     * @brief Updates the availability status of a book.
     *
     * Toggles the availability of the given book.
     *
     * @param b Pointer to the Book object whose availability will be updated.
     * @return The new availability status of the book.
     */
    bool updateBookAvailablity(Book* b) const;

    /**
     * @brief Counts the total number of books in the inventory.
     *
     * Iterates through the inventory and counts the number of non-null entries.
     *
     * @return The total number of books in the inventory.
     */
    long countTotalBooks() const;

    /**
     * @brief Prints all books in the inventory along with their index.
     *
     * Iterates through the inventory and prints information about each non-null book.
     */
    void print() const;

    /**
     * @brief Checks if a book is available by its ISBN.
     *
     * Uses the ISBN hash to locate the book and check its availability.
     *
     * @param ISBN The ISBN of the book.
     * @return True if the book is available, false otherwise.
     */
    bool isBookAvailable(const long long int ISBN) const;

    /**
     * @brief Finds a book in the inventory by its ISBN.
     *
     * Uses the ISBN hash to locate and return the book.
     *
     * @param ISBN The ISBN of the book.
     * @return Pointer to the Book object, or nullptr if not found.
     */
    Book* findBookByISBN(const long long int ISBN) const;

    /**
     * @brief Finds a book in the inventory by its title.
     *
     * Searches through the inventory to find the first book with a matching title.
     *
     * @param title The title of the book.
     * @return Pointer to the Book object, or nullptr if not found.
     */
    Book* findBookByTitle(const string& title) const;

private:
    Book** books; ///< Array of pointers to the books in the inventory.
    int size; ///< The size of the inventory array.
};

#endif //LIBRARYMANAGEMENT_INVENTORY_H
