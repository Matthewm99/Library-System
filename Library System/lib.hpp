/*
Name: Joseph Jabile + Matthew Ng
Student Number: 21142640 + 21158005
Date: 12/03/2024
Course: SYDE 121
Design Project
File Name: lib.hpp
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book;
class LibUser;
class Student;
class Teacher;

#ifndef lib_hpp // Compiler directive that ensures that if code following ifndef is not already defined to include in compilation
#define lib_hpp // Compiler directive that ensures this file is compiled only once
#include "Book.hpp" // Includes declared book class in Book.hpp



// Library class
class Library{
    vector<Book*> books; // Vector library of books
    vector<bool> is_borrowed; // For indicating if a book is borrowed or not
    public:
        // Empty library constructor
        Library();

        //Parameterized constructor with vector of books
        Library(vector<Book*> inputted_books);
        Library(vector<bool> is_borrowed);

        //INPUTS: n/a
        //PURPOSE: Printing out the library
        //OUTPUTS: Every value in the library
        void print();

        //INPUTS: Book class, book object
        //PURPOSE: insert a Book instance passed in by value. The provided values are stored as a new Book object    
        //inside the vector attribute
        //OUTPUTS: returns true if book was successfully added
        bool insert(Book* book);

        //INPUTS: Book class, book object
        //PURPOSE: remove a Book instance where a Book instance is passed in by value
        //OUTPUTS: returns true if book was successfully removed
        bool remove(Book* book);

        //INPUTS: LibUser& user, const string& title
        //PURPOSE: allows for books to be borrowed to users
        //OUTPUTS: returns true if book was successfully borrowed
        bool borrow_book (LibUser* user, string title); 


        //INPUTS: LibUser& user, const string& title
        //PURPOSE: allows for books to be returned to users
        //OUTPUTS: returns true if book was successfully returned
        bool return_book (LibUser* user, string title);

        //INPUTS: string title, string authors, string genre
        //PURPOSE: allows for books to be searched based on substrings of attributes
        //OUTPUTS: no returns
        void advanced_search(string title, string authors, string genre);

        
    };
#endif
