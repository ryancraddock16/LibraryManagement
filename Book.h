//
// Created by Joseph Campione on 11/12/24.
//

#ifndef LIBRARYMANAGEMENT_BOOK_H
#define LIBRARYMANAGEMENT_BOOK_H

#include <string>

using namespace std;

/**
 * @class Book
 * @brief Represents a book in the library management system.
 *
 * This class holds information about a book, including its title, author, genre, publication year,
 * ISBN, availability status, fines, and days checked out. It provides methods to access and modify
 * these properties, as well as to compare books and generate a detailed book description.
 */
class Book {
public:
    /**
     * @brief Default constructor for the Book class.
     * Initializes a book with default values.
     */
    Book();

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
    Book(string title, string author, string genre, short publicationYear, long long isbn,
         bool isAvailable);

    /**
     * @brief Get the title of the book.
     *
     * @return The title of the book.
     */
    const string &getTitle() const;

    /**
     * @brief Set the title of the book.
     *
     * @param title The new title for the book.
     */
    void setTitle(const string &title);

    /**
     * @brief Get the author of the book.
     *
     * @return The author of the book.
     */
    const string &getAuthor() const;

    /**
     * @brief Set the author of the book.
     *
     * @param author The new author for the book.
     */
    void setAuthor(const string &author);

    /**
     * @brief Get the genre of the book.
     *
     * @return The genre of the book.
     */
    const string &getGenre() const;

    /**
     * @brief Set the genre of the book.
     *
     * @param genre The new genre for the book.
     */
    void setGenre(const string &genre);

    /**
     * @brief Get the publication year of the book.
     *
     * @return The publication year of the book.
     */
    short getPublicationYear() const;

    /**
     * @brief Set the publication year of the book.
     *
     * @param publicationYear The new publication year for the book.
     */
    void setPublicationYear(short publicationYear);

    /**
     * @brief Get the ISBN of the book.
     *
     * @return The ISBN of the book.
     */
    long long getIsbn() const;

    /**
     * @brief Set the ISBN of the book.
     *
     * @param isbn The new ISBN for the book.
     */
    void setIsbn(long long isbn);

    /**
     * @brief Check if the book is available.
     *
     * @return true if the book is available, false otherwise.
     */
    bool isAvailable() const;

    /**
     * @brief Set the availability of the book.
     *
     * @param isAvailable The new availability status of the book.
     */
    void setIsAvailable(bool isAvailable);

    /**
     * @brief Compare two books based on their ISBN.
     *
     * @param b The book to compare with.
     * @return true if the current book's ISBN is less than the other book's ISBN.
     */
    bool operator<(const Book &b) const;

    /**
     * @brief Compare two books for equality based on their ISBN.
     *
     * @param b The book to compare with.
     * @return true if the current book's ISBN is equal to the other book's ISBN.
     */
    bool operator==(const Book &b) const;

    /**
     * @brief Get detailed information about the book.
     *
     * @return A string containing the book's title, author, genre, ISBN, publication year, availability status, fines, and days checked out.
     */
    string getInfo() const;

    /**
     * @brief Get the fine associated with the book.
     *
     * @return The fine amount for the book.
     */
    int getFine() const;

    /**
     * @brief Set the fine associated with the book.
     *
     * @param fine The new fine amount for the book.
     */
    void setFine(int fine);

    /**
     * @brief Get the number of days the book has been checked out.
     *
     * @return The number of days the book has been checked out.
     */
    int getDaysCheckedOut() const;

    /**
     * @brief Set the number of days the book has been checked out.
     *
     * @param daysCheckedOut The new number of days the book has been checked out.
     */
    void setDaysCheckedOut(int daysCheckedOut);

private:
    string title; ///< The title of the book.
    string author; ///< The author of the book.
    string genre; ///< The genre of the book.
    short publicationYear; ///< The year the book was published.
    long long ISBN; ///< The ISBN of the book.
    bool available; ///< Availability status of the book.
    int fine; ///< The fine associated with the book.
    int daysCheckedOut; ///< The number of days the book has been checked out.
};

#endif //LIBRARYMANAGEMENT_BOOK_H
