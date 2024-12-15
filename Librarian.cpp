//
// Created by Joseph Campione on 12/2/24.
//

#include "Librarian.h"
#include "LibraryHash.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


/**
 * @brief Default constructor for Librarian.
 *
 * Initializes the checkOut vector and loads the book inventory from a CSV file.
 * It populates the `inventory` with Book objects, and also tracks the books that are checked out.
 */
Librarian::Librarian() {
    checkOut.reserve(10);
    ifstream file("../Extras/BookInventory.csv");
    vector<vector<string>> tempVec;
    string discard;
    if(!file.is_open()){
        cout << "not open" << endl;
    }
    file >> discard;
    while(file){
        string line, temp;
        getline(file, line);
        stringstream ss(line);
        vector<string> tempStringVec;
        while(getline(ss,temp,',')){
            tempStringVec.push_back(temp);
        }
        tempVec.push_back(tempStringVec);
    }
    file.close();

    for(int i = 0; i < tempVec.size(); i++){
        if (tempVec[i].size() == 6) {
            string title = tempVec[i].at(1);
            long long ISBN = LibraryHash::formatISBN(tempVec[i].at(0));
            string author = tempVec[i].at(2);
            string genre = tempVec[i].at(3);
            short pubYear = stoi(tempVec[i].at(4));
            string boolTemp = tempVec[i].at(5);
            transform(boolTemp.begin(), boolTemp.end(), boolTemp.begin(), ::tolower);
            bool isAvailable = (boolTemp == "true");

            Book* book = new Book(title, author, genre, pubYear, ISBN, isAvailable);
            if(!book->isAvailable()){
                book->setDaysCheckedOut(10);
                checkOut.push_back(book);
            }

            inventory.addBook(book);
        } else {
            cout << "Skipping row " << i << " due to unexpected column count." << endl;
        }
    }
}

/**
 * @brief Checks out a book by its ISBN.
 *
 * Sets the book's availability to false, adds it to the `checkOut` list, and sets the number of days checked out.
 * If the book is already checked out, it reserves the book instead.
 *
 * @param ISBN The ISBN of the book to check out.
 * @return Pointer to the checked out book, or nullptr if the book is reserved instead.
 */
Book *Librarian::checkoutBook(long long ISBN)  {
    Book* b = inventory.findBookByISBN(ISBN);
    for(auto i : checkOut){
        if(b == i){
            reserveBook(ISBN);
            return nullptr;
        }
    }
    b->setDaysCheckedOut(10);
    b->setIsAvailable(false);
    checkOut.push_back(b);
    return b;
}

/**
 * @brief Checks out a book object.
 *
 * Sets the book's availability to false, adds it to the `checkOut` list, and sets the number of days checked out.
 * If the book is already checked out, it reserves the book instead.
 *
 * @param b Pointer to the Book object to check out.
 * @param ISBN ISBN of the book to check out.
 * @return Pointer to the checked out book, or nullptr if the book is reserved instead.
 */
Book *Librarian::checkoutBook(Book* b, long long ISBN)  {
    for(auto i : checkOut){
        if(b == i){
            reserveBook(ISBN);
            return nullptr;
        }
    }
    b->setDaysCheckedOut(10);
    b->setIsAvailable(false);
    checkOut.push_back(b);
    return b;
}

/**
 * @brief Returns a book by its ISBN.
 *
 * Finds the book in the inventory by ISBN and returns it.
 *
 * @param ISBN The ISBN of the book to return.
 */
void Librarian::returnBook(long long ISBN){
    returnBook(inventory.findBookByISBN(ISBN));
}

/**
 * @brief Returns a checked-out book to the inventory.
 *
 * Sets the book's availability to true and processes any reservations for the book.
 *
 * @param book Pointer to the Book object to return.
 */
void Librarian::returnBook(Book *book) {
    for(const auto & i : checkOut){
        if(book == i){
            book->setIsAvailable(true);
            processReservations();
            break;
        }
    }
}

/**
 * @brief Reserves a book by its ISBN.
 *
 * Adds the book to the reservation list if it is available.
 *
 * @param ISBN The ISBN of the book to reserve.
 */
void Librarian::reserveBook(const long long ISBN) {
    reservations.push_back(inventory.findBookByISBN(ISBN));
}

/**
 * @brief Cancels the reservation for a book by its ISBN.
 *
 * Removes the book from the reservation list.
 *
 * @param ISBN The ISBN of the book whose reservation to cancel.
 */
void Librarian::cancelReservation(const long long ISBN) {
    for (auto & reservation : reservations) {
        if(reservation->getIsbn() == ISBN){
            reservation = nullptr;
        }
    }
}

/**
 * @brief Processes all reservations for books.
 *
 * Checks out any reserved books that are now available.
 */
void Librarian::processReservations() {
    for(auto & reservation : reservations){
        if(reservation->isAvailable()){
            checkoutBook(reservation->getIsbn());
            reservation = nullptr;
        }
    }
}

/**
 * @brief Renews a book by extending its checkout period.
 *
 * Updates the number of days the book has been checked out.
 *
 * @param ISBN The ISBN of the book to renew.
 * @param days The number of days to extend the checkout period.
 */
void Librarian::renewBook(long long int ISBN, int days) const {
    inventory.findBookByISBN(ISBN)->setDaysCheckedOut(days);
}

/**
 * @brief Processes overdue books and calculates fines.
 *
 * Reduces the number of days checked out for each book and calculates any fines for overdue books.
 *
 * @param days The number of days the overdue books are behind.
 */
void Librarian::processOverdueBooks(const int days) const {
    for(auto i : checkOut){
        i->setDaysCheckedOut(i->getDaysCheckedOut()-days);
        calculateFine(i);
    }
}

/**
 * @brief Calculates the fine for a book based on how many days it is overdue.
 *
 * If the book is overdue, it calculates the fine by multiplying the negative number of days by 10.
 *
 * @param book Pointer to the Book object for which to calculate the fine.
 */
void Librarian::calculateFine(Book *book) const {
    for(auto i : checkOut){
        if(i->getDaysCheckedOut() < 0) {
            i->setFine(i->getDaysCheckedOut()*-10);
        }
    }
}

/**
 * @brief Adds a new book to the inventory.
 *
 * Adds the given book to the inventory and updates the book's availability.
 *
 * @param book Pointer to the Book object to add.
 */
void Librarian::addNewBook(Book *book) const {
    inventory.addBook(book);
}


/**
 * @brief Removes a book from the inventory.
 *
 * Removes the given book from the inventory.
 *
 * @param ISBN ISBN of the book to be removed
 */
void Librarian::removeBookFromInventory(long long ISBN) {
    inventory.removeBook(ISBN);
}

/**
 * @brief Removes a book from the inventory.
 *
 * Removes the given book from the inventory.
 *
 * @param book Pointer to the Book object to remove.
 */
void Librarian::removeBookFromInventory(Book *book) const {
    inventory.removeBook(book);
}

/**
 * @brief Lists all books in the inventory.
 *
 * Prints all books in the inventory to the console.
 */
void Librarian::listAllBooks() const {
    inventory.print();
}

/**
 * @brief Lists all overdue books.
 *
 * Prints information about books that are overdue.
 */
void Librarian::listOverdueBooks() const {
    for(auto i : checkOut){
        if(i->getDaysCheckedOut() < 0 ){
            cout << i->getInfo() << endl;
        }
    }
}

/**
 * @brief Lists all book reservations.
 *
 * Prints information about books that are currently reserved.
 */
void Librarian::listReservations() const {
    for(auto i : reservations){
        cout << i->getInfo() << endl;
    }
}

/**
 * @brief Searches for a book by its title.
 *
 * Searches the inventory for a book with the specified title.
 *
 * @param title The title of the book to search for.
 * @return Pointer to the Book object if found, nullptr if not found.
 */
Book *Librarian::searchBooks(const string &title) const {
    return inventory.findBookByTitle(title);
}

/**
 * @brief Searches for a book by its ISBN.
 *
 * Searches the inventory for a book with the specified ISBN.
 *
 * @param ISBN The ISBN of the book to search for.
 * @return Pointer to the Book object if found, nullptr if not found.
 */
Book *Librarian::searchBooks(const long long int ISBN) const {
    return inventory.findBookByISBN(ISBN);
}
