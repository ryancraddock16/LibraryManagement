# Library Management: CSC 104 Final Project

##  Project Overview 
This program can be used to manage a Librarians inventory of books using a 
text based interface. This program is a lightweight way to manage books in a librarians inventory, 
and make it easier for them to manage reservations and to manage check-outs. 

## Design Specifications 
This program uses three classes to achieve this, Books, Inventory, and Librarian.
I chose not to use inheritance for classes as I did not think it would be necessary and that it would over complicate 
the code for these classes. The Inventory does have an "accessory" class, Library Hash, which implements the HashMap 
which I will be getting into later. I chose to use a HashMap because of my prior knowledge of the structure
and because it made the most sense for this use case, which I will go into more detail later about. All of my methods 
are based around editing attributes of the book class, and making it as easy as possible to do so. 
This implementation was the most efficient, by access time and simplest to use by the user that I was able to create for 
this circumstance. 

## Data Structures 
The data structure which this program is centered around is the hash-map. This, in my view, was the best because of its
low access time. I used the ISBN of the book, and based my hash value off of that, making for an implementation that is 
not adding on storage or another attribute to the book class, but only using a pre-existent one. If I had more time, one
improvement I could make is the usage of a binary search tree so that in the unlikely case of two ISBN producing the same value 
it would not produce an error, which is one point of possible error in the project. This likelihood is low however, as I used a 
large prime number to base my HashKey off of, making it unlikely that diving it by a number would produce the same value. 

## Object Oriented Programming 
This entire project is mainly based around the book class, which has instances created and then pointed too by the inventory class. 
This project uses some static methods to handle basic data processing, and some methods in the inventory class which correspond to methods 
in the librarian class to find and retrieve books from the Hash Map. 

## Pointers and references
This entire program is centered around the use of pointers to instances of Books, and using references of books to manipulate and 
know what user currently has a book checked out, and then track reservations through pointers to 
the reserved book. 

## File IO 
The program uses a basic file input system to take the preexisting BookInventory.csv file and put the data from it into a 
2d vector for data processing using streams. 

## Error Handling 
This program uses basic error handling to determine if the file is not in the correct spot or if the user inputted something incorrect
it returns null pointers when something is not found to be in the correct place, which produces a error message. 

## Testing
Most of the code in this project is basic boilerplate code, and much of the logic was handled in a few methods, so 
fortunately I was able to do only a bit of testing until I was able to do a full code test at the very end. That means 
I was able to test for full system errors, and handle them when they came up, and know how each class interacted 
with the other more efficiently. 

## Challenges 
The biggest challenge in this project was managing pointers and managing references, as everything else I had some prior knowledge
and experience on how to do. I had to learn how pointers interacted with each-other, and how to effectively the situation when multiple pointers 
are pointing to the same thing. I solved this by more learning, and choosing to center my project around pointers instead of 
references, which makes it easier to manage when multiple data structures are pointing to one book. 

## UML diagram
The UML Diagram is found in two places, both online at https://ultrapheonix.github.io/LibraryManagement/ and 
found here
![UML Diagram](Extras/UMLDiagram.png)

## Code Snippets 
The entire project is centered around this method, which is my static hash method
```c++
int LibraryHash::HashBook(const Book *b, const int size) {
    return static_cast<int>(b->getIsbn()/4943)%size;
}
```

This method is key to taking in the newly created book, taking its ISBN and then diving it by 4943, a large prime number, 
and then putting it at that index in the array. 

## Reflection 
Overall, I found this project got me substantially more conformable with C++ and how to work with it. This project
gave me a good base to build more experience off of. I appreciated how this project put into practice many of the things that 
I have been learning in CSC 104, and how it allowed me to grow in my overall coding ability, both in and out of C++. 

