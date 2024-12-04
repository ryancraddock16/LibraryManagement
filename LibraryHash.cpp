//
// Created by Joseph Campione on 11/22/24.
//

#include "LibraryHash.h"


/**
 * @brief converts the book to a hash value using the ISBN
 * @param b pointer to a book
 * @param size size of the hashmap
 * @return Hash value
 */
int LibraryHash::HashBook(const Book *b, const int size) {
    return static_cast<int>(b->getIsbn()/4943)%size;
}

/**
 * @brief Converts the ISBN to a hash value
 * @param ISBN ISBN of a book
 * @param size size of the hashmap
 * @return hashmap value
 */
int LibraryHash::ISBNToHash(const long long int ISBN, const int size) {
    return static_cast<int>((ISBN/4943)%size);
}

/**
 * @param inputString formats the ISBN into a usable long long instead of a string
 * @return the formatted ISBN in long long
 */
long long LibraryHash::formatISBN(string& inputString){
    for(int i = 0; i < inputString.length(); i++){
        if(!isdigit(inputString[i])){
            inputString.erase(inputString.begin() + i);
        }
    }
    return stoll(inputString);
}
