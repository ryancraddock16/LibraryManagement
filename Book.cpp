#include "Book.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor for the Book class.
 * Initializes a book with default values.
 */
Book::Book() {
    title = "untitled";
    author = "unknown";
    genre = "unknown";
    publicationYear = -1;
    ISBN = -1;
    available = true;
    daysCheckedOut = 0;
    fine = 0;
}

/**
 * @brief Parameterized constructor for the Book class.
 * Initializes a book with the provided details.
 *
 * @param title Title of the book.
 * @param author Author of the book.
 * @param genre Genre of the book.
 * @param publicationYear Year the book was published.
 * @param isbn ISBN of the book.
 * @param isAvailable Availability of the book (true if available).
 */
Book::Book(string title, string author, string genre, short publicationYear, long long isbn,
           bool isAvailable) : title(std::move(title)), author(std::move(author)), genre(std::move(genre)), publicationYear(publicationYear), ISBN(isbn),
                               available(isAvailable) { fine = 0; daysCheckedOut = 0;}

/**
 * @brief Get the title of the book.
 *
 * @return The title of the book.
 */
const string &Book::getTitle() const {
    return title;
}

/**
 * @brief Set the title of the book.
 *
 * @param title The new title for the book.
 */
void Book::setTitle(const string &title) {
    Book::title = title;
}

/**
 * @brief Get the author of the book.
 *
 * @return The author of the book.
 */
const string &Book::getAuthor() const {
    return author;
}

/**
 * @brief Set the author of the book.
 *
 * @param author The new author for the book.
 */
void Book::setAuthor(const string &author) {
    Book::author = author;
}

/**
 * @brief Get the genre of the book.
 *
 * @return The genre of the book.
 */
const string &Book::getGenre() const {
    return genre;
}

/**
 * @brief Set the genre of the book.
 *
 * @param genre The new genre for the book.
 */
void Book::setGenre(const string &genre) {
    Book::genre = genre;
}

/**
 * @brief Get the publication year of the book.
 *
 * @return The publication year of the book.
 */
short Book::getPublicationYear() const {
    return publicationYear;
}

/**
 * @brief Set the publication year of the book.
 *
 * @param publicationYear The new publication year for the book.
 */
void Book::setPublicationYear(short publicationYear) {
    Book::publicationYear = publicationYear;
}

/**
 * @brief Get the ISBN of the book.
 *
 * @return The ISBN of the book.
 */
long long Book::getIsbn() const {
    return ISBN;
}

/**
 * @brief Set the ISBN of the book.
 *
 * @param isbn The new ISBN for the book.
 */
void Book::setIsbn(long long isbn) {
    ISBN = isbn;
}

/**
 * @brief Check if the book is available.
 *
 * @return true if the book is available, false otherwise.
 */
bool Book::isAvailable() const {
    return available;
}

/**
 * @brief Set the availability of the book.
 *
 * @param isAvailable The new availability status of the book.
 */
void Book::setIsAvailable(bool isAvailable) {
    Book::available = isAvailable;
}

/**
 * @brief Compare two books based on their ISBN.
 *
 * @param b The book to compare with.
 * @return true if the current book's ISBN is less than the other book's ISBN.
 */
bool Book::operator<(const Book &b) const {
    return b.ISBN < ISBN;
}

/**
 * @brief Compare two books for equality based on their ISBN.
 *
 * @param b The book to compare with.
 * @return true if the current book's ISBN is equal to the other book's ISBN.
 */
bool Book::operator==(const Book &b) const {
    return b.ISBN == ISBN;
}

/**
 * @brief Get detailed information about the book.
 *
 * @return A string containing the book's title, author, genre, ISBN, publication year, availability status, fines, and days checked out.
 */
string Book::getInfo() const {
    return "Title: " + title +
           " Author: " + author +
           " Genre: " + genre +
           " ISBN: " + to_string(ISBN) +
           " Publication Year: " + to_string(publicationYear) +
           " Available: " + (available ? "Yes" : "No") +
           " Fines: " + to_string(fine) +
           " Days Left: " + to_string(daysCheckedOut);
}

/**
 * @brief Get the fine associated with the book.
 *
 * @return The fine amount for the book.
 */
int Book::getFine() const {
    return fine;
}

/**
 * @brief Set the fine associated with the book.
 *
 * @param fine The new fine amount for the book.
 */
void Book::setFine(int fine) {
    Book::fine = fine;
}

/**
 * @brief Get the number of days the book has been checked out.
 *
 * @return The number of days the book has been checked out.
 */
int Book::getDaysCheckedOut() const {
    return daysCheckedOut;
}

/**
 * @brief Set the number of days the book has been checked out.
 *
 * @param daysCheckedOut The new number of days the book has been checked out.
 */
void Book::setDaysCheckedOut(int daysCheckedOut) {
    Book::daysCheckedOut = daysCheckedOut;
}
