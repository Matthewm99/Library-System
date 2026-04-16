/*
Name: Joseph Jabile + Matthew Ng
Student Number: 21142640 + 21158005
Date: 12/03/2024
Course: SYDE 121
Design Project
File Name: main.cpp

The purpose of this program is to make a library with books. 
Each book is derived from classes, with headerfiles.
This program tests each method and constructor with different scenarios.
*/
#include <iostream>
#include "lib.hpp"
#include "LibraryUser.hpp"
#include "Book.hpp"

using namespace std;

int main() {

    // Making new books
    Book* book1 = new Book("Diary of Wimpy Kid", "Jeff Kinney", "2007", "Fiction");
    Book* book2 = new Book("Born a Crime", "Trevor Noah", "2016", "Non-Fiction");
    Book* book3 = new Book("To Kill a Mockingbird", "Harper Lee", "1960", "Fiction");
    Book* book4 = new Book("Meditations", "Marcus Aurelius", "150", "Philosophy");
    Book* book5 = new Book("Man's Search for Meaning", "Victor Frankl", "1975", "Philosophy");
    Book* book6 = new Book("Harry Potter and the Philosopher's stone", "J.K. Rowling", "1997", "Fantasy");
    Book* book7 = new Book("Narnia", "C.S, Lewis", "1998", "Fiction");

    // Testing vector method of inserting books
     vector<Book *> bookshelf = {book1, book2, book3};

    // Creating Library
    Library library(bookshelf);
    
    // Inserting rest of books into library
    library.insert(book4);
    library.insert(book5);
    library.insert(book6);
    library.insert(book7);

    cout << "\n--- Initial Library Contents ---\n";
    library.print();

    // Creating Student and Teacher Users
    Student student(false, "Jermaine Cole", "S114", 0);  // Not graduated
    Teacher teacher("Prof. Nehaniv", "T001", 0);

    // Printing Users
    cout << "\n--- Users Created ---\n";
    student.print();
    teacher.print();

    // Testing book borrowing
     cout << "\n--- Users Borrowing books ---\n";
    library.borrow_book(&student, "Clean Code");
    library.borrow_book(&student, "Narnia");
    library.borrow_book(&student, "To Kill a Mockingbird");
    library.borrow_book(&student, "Meditations");
    library.borrow_book(&student, "Born a Crime");
    library.borrow_book(&teacher, "Clean Code"); // Should return that it is already borrowed
    library.borrow_book(&teacher, "Diary of Wimpy Kid");

    // Testing borrow limit
    cout << "\n--- Student borrowing over limit ---\n";
    
    library.borrow_book(&student, "Green Eggs and Ham");

    // Print Library after borrowing
    cout << "\n--- Library After Borrowing ---\n";
    library.print();

    // Advanced Search
    cout << "\n--- Advanced Search ---\n";
    library.advanced_search("", "Trevor Noah", ""); //Search by Author (1 result)
    library.advanced_search("Narnia", "", ""); //Search by Title (1 result)
    library.advanced_search("", "", "Fiction"); // Search by Genre (3 results)
    library.advanced_search("sdjaiodj", ",", "dsaidop"); // Returns invalid

    // Returning Books
    cout << "\n--- Returning Books ---\n";
    library.return_book(&student, "Narnia");
    library.return_book(&student, "1984");
    library.return_book(&student, "Narnia"); // Should not return 

    cout << "\n--- Library Contents After Returning ---\n";
    library.print();

    // Adding a New Book by a Teacher
    Book* book8 = new Book("Refactoring", "Martin Fowler", "1999", "Software Engineering");
    teacher.add_book_to_library(library, book8);

    cout << "\n--- Library Contents After Adding a Book ---\n";
    library.print();

    // Removing Books
    cout << "\n--- Removing a Book ---\n";
    library.remove(book3); // Removes book 3
    library.remove(book2); // Removes book 2
    library.remove(book2); // Should return that it removed nothing

    cout << "\n--- Final Library Contents ---\n";
    library.print();

    cout << "\n -- Final User Contents -- \n";
    student.print();
    teacher.print();
    
    return 0;
}
