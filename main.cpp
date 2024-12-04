#include <iostream>
#include "Librarian.h"

int main() {
    Librarian l;
    l.listAllBooks();
    l.checkoutBook(9780307291367);
    l.processOverdueBooks(15);
    Book* temp = new Book("The Martian", "Andy Weir", "Sci-Fi", 2011, 9780553418026,true);
    l.addNewBook(temp);
    l.checkoutBook(9780553418026);
    l.checkoutBook(9780553418026);
    l.listOverdueBooks();
    l.listReservations();
    l.returnBook(temp);
    l.listReservations();

    return 0;

}
