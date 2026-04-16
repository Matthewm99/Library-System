/*
Name: Joseph Jabile + Matthew Ng
Student Number: 21142640 + 21158005
Date: 12/03/2024
Course: SYDE 121
Design Project
File Name: Book.hpp
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


#ifndef book_hpp 
#define book_hpp 

// PURPOSE: stores book title, authors, and date of publication
class Book{
    string title;
    string authors; 
    string date_of_publication;
    string genre;
    public:
        Book();
        Book(string new_title);
        Book(string new_title,  string new_authors); 
        Book(string new_title,  string new_authors,  string new_date_of_publication); 
        Book(string new_title, string new_authors, string new_date_of_publication, string new_genre);
        // Method declaration to print
        void print();

        // Equality operator overloading to compare book titles, authors and date_of_publications currently in the library with attempted insertions
        bool operator==(const Book& other_book) const;

        // Getter method to return attributes of books
        string get_title();
        string get_authors();
        string get_date_of_publication();
        string get_genre();
    };
#endif
