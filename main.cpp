#include <iostream>
#include "Librarian.h"
#include "LibraryHash.h"

using namespace std;
int main() {
    Librarian l;

    char userOption;
    string ISBN, title, authorName, genre;
    short pubYear;
    long long num;
    int days;
    Book* b;

    while (userOption != 'q') {
        cout << "Options: " << endl;
        cout << "   1- Checkout book. 2- Return book. 3- Reserve Book. 4- Cancel Reservation. 5- Renew Book." <<
                 endl << "   6- Add New Book. 7- Remove Book. 8- Search Books. O- List Overdue Books. R- List Reservations. " <<
                    " L- List Books. q- Quit program" << endl;
        cin >> userOption;
        switch (userOption) {
            case '1':
                cout << "Enter ISBN: " << endl;
                cin >> ISBN;
                num = LibraryHash::formatISBN(ISBN);
                l.checkoutBook(num);
                break;
            case '2':
                cout << "Enter ISBN: " << endl;
                cin >> ISBN;
                num = LibraryHash::formatISBN(ISBN);
                l.returnBook(num);
                break;
            case '3':
                cout << "Enter ISBN: " << endl;
                cin >> ISBN;
                num = LibraryHash::formatISBN(ISBN);
                l.reserveBook(num);
                break;
            case '4':
                cout << "Enter ISBN: " << endl;
                cin >> ISBN;
                num = LibraryHash::formatISBN(ISBN);
                l.cancelReservation(num);
                break;
            case '5':
                cout << "Enter ISBN: " << endl;
                cin >> ISBN;
                num = LibraryHash::formatISBN(ISBN);
                cout << "How many days? : " << endl;
                cin >> days;
                l.renewBook(num, days);
                break;
            case '6':
                cout << "Enter Title: " << endl;
                cin.ignore();
                getline(cin, title);
                cout << "Enter Author: " << endl;

                getline(cin, authorName);
                cout << "Enter ISBN: " << endl;

                getline(cin, ISBN);
                num = LibraryHash::formatISBN(ISBN);
                cout << "Enter Genre: " << endl;

                getline(cin, genre);
                cout << "Enter Publisher Year: " << endl;
                cin >> pubYear;
                b = new Book(title, authorName, genre, pubYear,num, true);
                l.addNewBook(b);
                break;
            case '7':
                cout << "Enter ISBN: " << endl;
                cin >> ISBN;
                num = LibraryHash::formatISBN(ISBN);
                l.removeBookFromInventory(num);
                break;
            case 'L':
                l.listAllBooks();
                break;
            case 'O':
                l.listOverdueBooks();
                break;
            case 'R':
                l.listReservations();
                break;
            default:
                cout << "Invalid Input." << endl;
                break;
        }
    }

    return 0;
}
