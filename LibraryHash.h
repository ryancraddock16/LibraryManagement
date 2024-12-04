//
// Created by Joseph Campione on 11/22/24.
//

#ifndef LIBRARYMANAGEMENT_LIBRARYHASH_H
#define LIBRARYMANAGEMENT_LIBRARYHASH_H

#include "Book.h"
#include <vector>

using namespace std;

/**
 * @class LibraryHash
 * @brief Static methods for managing the hash values used in the library system.
 *
 * The `LibraryHash` class contains static methods that handle the hashing logic used to efficiently
 * store and retrieve books in the library inventory. It provides methods for hashing a book,
 * converting an ISBN to a hash value, and formatting an ISBN string to a standard numeric format.
 */
class LibraryHash {
public:
    /**
     * @brief Computes a hash value for a book object based on its ISBN.
     *
     * This method generates a hash value for a book using a hash function. The result is then
     * mapped to an index based on the size of the inventory.
     *
     * @param b The Book object whose hash value is to be computed.
     * @param size The size of the inventory array.
     * @return A hash value representing the book's position in the inventory.
     */
    static int HashBook(const Book* b, int size);

    /**
     * @brief Converts an ISBN number into a hash value.
     *
     * This method converts an ISBN into a hash value that can be used to determine the
     * book's position in the inventory.
     *
     * @param ISBN The ISBN of the book.
     * @param size The size of the inventory array.
     * @return A hash value representing the ISBN's position in the inventory.
     */
    static int ISBNToHash(long long ISBN, int size);

    /**
     * @brief Formats an ISBN string to a long long integer.
     *
     * This method takes an ISBN string and formats it into a long long integer value.
     * It removes any non-numeric characters and ensures the ISBN is in the correct format.
     *
     * @param inputString The ISBN string to be formatted.
     * @return The formatted ISBN as a long long integer.
     */
    static long long formatISBN(string& inputString);
};

#endif //LIBRARYMANAGEMENT_LIBRARYHASH_H
