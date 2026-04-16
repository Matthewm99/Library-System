/*
Name: Joseph Jabile + Matthew Ng
Student Number: 21142640 + 21158005
Date: 12/03/2024
Course: SYDE 121
Design Project
File Name: Library.hpp
*/
#include <iostream>
#include <vector>
#include <string>

#include "lib.hpp" 
#include "Book.hpp"

using namespace std;

#ifndef libuser_hpp 
#define libuser_hpp 

class LibUser{
    string name;
    string user_id;
    int borrowed_count;

    public:
        LibUser(); // Default Constructor
        LibUser(string name, string user_id, int borrowed_count); // Parameterized Constructor

        virtual int get_borrowed_limit() const = 0; // Pure virtual method for borrow limit

        string get_name() const; // Returns name

        string get_user_id() const; // Returns user ID

        int get_borrowed_count() const; // Returns borrowed count

        void borrow_book(); // Increments borrowed book count

        void return_book(); // Decrements borrowed book count

        virtual void print() const;
        

};

class Student: public LibUser{
    bool graduated; // Boolean value to determine if graduated
    const int BORROWED_LIMIT; // Borrow limit constant
   
    public:
    Student(); // Default Constructor
    Student(bool graduated, string name, string user_id, int borrowed_count); // Parameterized Constructor 

    int get_borrowed_limit() const override;
    void print() const override;

};

class Teacher: public LibUser{

    const int BORROWED_LIMIT;
    

    public:
    Teacher(); // Default Constructor
    Teacher(string name, string user_id, int borrowed_count); // Parameterized Constructor

    bool add_book_to_library(Library& library, Book* book); // Adds Book to library
    int get_borrowed_limit() const override;
    void print() const override;

};
#endif