//
// Created by Joseph Campione on 12/2/24.
//

#ifndef LIBRARYMANAGEMENT_LIBRARIAN_H
#define LIBRARYMANAGEMENT_LIBRARIAN_H

#include "Inventory.h"
#include <vector>

/**
 * @class Librarian
 * @brief Manages the library's book inventory, checkout system, reservations, and overdue books.
 *
 * The `Librarian` class provides functionality for managing books in a library system. It handles checking
 * out books, returning them, managing reservations, processing overdue books, and calculating fines.
 * It also allows searching, adding, and removing books from the library's inventory.
 * The class tracks the availability of books and ensures that books are properly checked out or reserved.
 */

class Librarian {
public:
    /**
     * @brief Default constructor for Librarian.
     *
     * Initializes the checkOut vector and loads the book inventory from a CSV file.
     * It populates the `inventory` with Book objects and also tracks the books that are checked out.
     */
    Librarian();

    /**
     * @brief Checks out a book by its ISBN.
     *
     * Sets the book's availability to false, adds it to the `checkOut` list, and sets the number of days checked out.
     * If the book is already checked out, it reserves the book instead.
     *
     * @param ISBN The ISBN of the book to check out.
     * @return Pointer to the checked-out book, or nullptr if the book is reserved instead.
     */
    Book* checkoutBook(long long ISBN);

    /**
     * @brief Checks out a book object.
     *
     * Sets the book's availability to false, adds it to the `checkOut` list, and sets the number of days checked out.
     * If the book is already checked out, it reserves the book instead.
     *
     * @param b Pointer to the Book object to check out.
     * @param ISBN ISBN of the book to check out.
     * @return Pointer to the checked-out book, or nullptr if the book is reserved instead.
     */
    Book* checkoutBook(Book* b, long long ISBN);

    /**
     * @brief Returns a book by its ISBN.
     *
     * Finds the book in the inventory by ISBN and returns it.
     *
     * @param ISBN The ISBN of the book to return.
     */
    void returnBook(long long ISBN);

    /**
     * @brief Returns a checked-out book to the inventory.
     *
     * Sets the book's availability to true and processes any reservations for the book.
     *
     * @param book Pointer to the Book object to return.
     */
    void returnBook(Book* book);

    /**
     * @brief Reserves a book by its ISBN.
     *
     * Adds the book to the reservation list if it is available.
     *
     * @param ISBN The ISBN of the book to reserve.
     */
    void reserveBook(long long ISBN);

    /**
     * @brief Cancels the reservation for a book by its ISBN.
     *
     * Removes the book from the reservation list.
     *
     * @param ISBN The ISBN of the book whose reservation to cancel.
     */
    void cancelReservation(long long ISBN);

    /**
     * @brief Processes all reservations for books.
     *
     * Checks out any reserved books that are now available.
     */
    void processReservations();

    /**
     * @brief Renews a book by extending its checkout period.
     *
     * Updates the number of days the book has been checked out.
     *
     * @param ISBN The ISBN of the book to renew.
     * @param days The number of days to extend the checkout period.
     */
    void renewBook(long long ISBN, int days) const;

    /**
     * @brief Processes overdue books and calculates fines.
     *
     * Reduces the number of days checked out for each book and calculates any fines for overdue books.
     *
     * @param days The number of days the overdue books are behind.
     */
    void processOverdueBooks(int days) const;

    /**
     * @brief Calculates the fine for a book based on how many days it is overdue.
     *
     * If the book is overdue, it calculates the fine by multiplying the negative number of days by 10.
     *
     * @param book Pointer to the Book object for which to calculate the fine.
     */
    void calculateFine(Book* book) const;

    /**
     * @brief Adds a new book to the inventory.
     *
     * Adds the given book to the inventory and updates the book's availability.
     *
     * @param book Pointer to the Book object to add.
     */
    void addNewBook(Book* book) const;

    /**
     * @brief Removes a book from the inventory.
     *
     * Removes the given book from the inventory.
     *
     * @param book Pointer to the Book object to remove.
     */
    void removeBookFromInventory(Book* book) const;

    /**
     * @brief Lists all books in the inventory.
     *
     * Prints all books in the inventory to the console.
     */
    void listAllBooks() const;

    /**
     * @brief Lists all overdue books.
     *
     * Prints information about books that are overdue.
     */
    void listOverdueBooks() const;

    /**
     * @brief Lists all book reservations.
     *
     * Prints information about books that are currently reserved.
     */
    void listReservations() const;

    /**
     * @brief Searches for a book by its title.
     *
     * Searches the inventory for a book with the specified title.
     *
     * @param title The title of the book to search for.
     * @return Pointer to the Book object if found, nullptr if not found.
     */
    [[nodiscard]] Book* searchBooks(const std::string& title) const;

    /**
     * @brief Searches for a book by its ISBN.
     *
     * Searches the inventory for a book with the specified ISBN.
     *
     * @param ISBN The ISBN of the book to search for.
     * @return Pointer to the Book object if found, nullptr if not found.
     */
    [[nodiscard]] Book* searchBooks(long long ISBN) const;

private:
    Inventory inventory; ///< The inventory of books in the library.
    std::vector<Book*> reservations; ///< List of books that are reserved.
    std::vector<Book*> checkOut; ///< List of books that are checked out.
};

#endif //LIBRARYMANAGEMENT_LIBRARIAN_H
