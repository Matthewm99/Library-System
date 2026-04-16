/*
Name: Joseph Jabile + Matthew Ng
Student Number: 21142640 + 21158005
Date: 12/03/2024
Course: SYDE 121
Design Project
File Name: lib.cpp
*/
#include "lib.hpp"
#include "LibraryUser.hpp"
#include <iostream>
#include <vector>
using namespace std;

// Default empty library constructor
Library::Library() : books() {}

// Parameterized constructor with vector
Library::Library(::vector<Book*> inputted_books) : books(inputted_books) {}
Library::Library(::vector<bool> is_borrowed) : is_borrowed(books.size(), false){};

// Method definition for print
void Library::print() {
  cout << "Books currently in library: " << books.size() << endl;
  for (int i = 0; i < books.size(); i++) {
    books[i]->print();
    cout << endl;
  }
}

// If the size of the library is 0, a book is inserted.
// After the size of the library is greater than 0, then the function continues
// to insert books, checking if they are duplicates and rejecting if so.
bool Library::insert(Book* book) {
    // Checking if the book already exists using the equality operator
    for (Book* existing_book : books) {
        if (*existing_book == *book) {
            cout << "Book titled '" << book->get_title() << "' already exists in the library.\n";
            return false;
        }
    }
    // Adding the book to the library
    books.push_back(book);
    is_borrowed.push_back(false); // Initially, the book is not borrowed
    cout << "Book titled '" << book->get_title() << "' added to the library.\n";
    return true;
}



// Searches through the vector attribute and removes the Book instance that
// matches the entered values. If an instance is found and removed, true is
// returned; else, false is returned.
bool Library::remove(Book* book) {
    for (int i = 0; i < books.size(); ++i) {
        if (*books[i] == *book) {
            string book_title = books[i]->get_title();
            delete books[i];
            books[i] = NULL;
            books.erase(books.begin() + i);
            is_borrowed.erase(is_borrowed.begin() + i);
            cout << "Book:" << book_title << " removed from the library.\n";
            return true;
        }
    }      
    cout << "Book: " << book << " not found in the library.\n";
    return false;
    
    
}




// Inputs a LibraryUser object and title of the book to be borrowed. If the input title matches the title of a book 
//in the library and it is not borrowed, and if the borrow_count for the user is smaller than borrow_limit for 
// them, the book can be borrowed to them. So, is_borrowed value for the book will be adjusted and user.borrow() 
// method will be called and a message will be printed that indicates the name of the user and title of the book 
// borrowed.

bool Library::borrow_book(LibUser* user, string title) {
  
    
    // Loop through all books to check availability
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i]->get_title() == title) {
            if (is_borrowed[i]){
                cout << "Book titled '" << title << "' is already borrowed.\n";
                return false;
            }
            if (user->get_borrowed_count() >= user->get_borrowed_limit()){
                cout << "User " << user->get_name() << " has reached their borrwing limit. They cannot borrow any more books.\n";
                return false;
            } 
                is_borrowed[i] = true;
                user->borrow_book();
                cout << user->get_name() << " has successfully borrowed '" << title << "' .\n'";
                return true;
            }
        }
          // If no available book with the given title was found
        cout << "Book titled '" << title << "' is not available for borrowing. \n";
        return false;
    }

  



// Implement an advanced search method that can search a book
// based on substrings of attributes. The search method inputs
//string values for title, author and genre that can be substring of
// the original title, author and genre of a book, and if a match is
// found prints book information, using book→print. If no match is
// found prints a message showing the book is not in the library
void Library::advanced_search(string title, string author, string genre) {
  bool found = false;
  for (Book *book : books) {
    if ((title.empty() || book->get_title().find(title) != string::npos) &&
        (author.empty() || book->get_authors().find(author) != string::npos) &&
        (genre.empty() || book->get_genre().find(genre) != string::npos)) {
      book->print();
      found = true;
    }
  }
  if (!found) {
    cout
        << "Book not found in library.\n";
  }
}


// This method inputs a LibraryUser object and title of the book to be returned. If the input title matches the 
// title of a book in the library and it is indicated as being borrowed, is_borrowed value for the book will be 
// adjusted and user.return() method will be called and a message will be printed that indicates the name of the 
// user and title of the book being returned.

bool Library::return_book(LibUser* user, string title) {
  for (int i = 0; i < books.size(); ++i) {
    if (books[i]->get_title() == title) {
        if(is_borrowed[i]){
            is_borrowed[i] = false;
            user->return_book();
            cout << "User " << user->get_name() << " has successfully returned the book '" << title << "'.\n";
            return true;
        }else{
            cout << "Book titled '" << title << "' is not currently borrowed, so it can't be returned.\n";
            return false;
        }
        
    }
  }
    cout << "Book titled '" << title << "' was not borrowed.\n";
  return false;
}