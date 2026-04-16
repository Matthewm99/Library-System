/*
Name: Joseph Jabile + Matthew Ng
Student Number: 21142640 + 21158005
Date: 12/03/2024
Course: SYDE 121
Design Project
File Name: LibraryUser.cpp
*/
#include <iostream>
#include <string>
#include "LibraryUser.hpp" // Includes class declaration
#include "lib.hpp" 
#include "Book.hpp"


using namespace std;

class Book;
class Student;
class Teacher;

        // Parameterized constructor for empty constructor
LibUser::LibUser() : name("N/A"), user_id("N/A"), borrowed_count(0){};
        // Parameterized constructor for libuser
LibUser::LibUser(string new_name, string new_user_id, int new_borrowed_count): 
    name(new_name), user_id(new_user_id), borrowed_count(new_borrowed_count){};

    // Increments the borrowed count when a book is borrowed
    void LibUser::borrow_book(){
        borrowed_count = borrowed_count + 1;
    }

    // Decrements the borrowed count when a book is returned
    void LibUser::return_book(){
        borrowed_count = borrowed_count - 1;
    }

    // Method definition for print
    void LibUser::print() const{
        cout << "Library User:" << endl;
        cout << "Name: " << name << endl;
        cout << "User ID: " << user_id << endl;
        cout << "Borrowed books: " << borrowed_count << endl;
        }

    // Getter method to return name
    string LibUser::get_name() const{
        return name;
    }

    // Getter method to return user id
    string LibUser::get_user_id() const{
        return user_id;
    }

    // Getter method to return borrowed count
    int LibUser:: get_borrowed_count() const{
        return borrowed_count;
    }

    // Parameterized constructor for empty constructor
    Student::Student() :  LibUser(), BORROWED_LIMIT(5), graduated(false){}

    // Parameterized constructor for student
    Student::Student(bool graduated, string name, string user_id, int borrowed_count) 
    : LibUser(name, user_id, borrowed_count), BORROWED_LIMIT(5), graduated(graduated) {}
    
    // Print method for student
    void Student::print() const{
        cout << "Graduated: " << (graduated ? "Yes" : "No") << endl;
        cout << "Student:" << endl;
        cout << "Name: " << get_name() << endl;
        cout << "User ID: " << get_user_id() << endl;
        cout << "Borrowed Limit: " << get_borrowed_limit() << endl;
        cout << "Borrowed books: " << get_borrowed_count() << endl;
        cout << "\n";
    }

    // Retrieves teacher borrow limit (getter method)
    int Student::get_borrowed_limit() const {
    return BORROWED_LIMIT; 
}

    // Parameterized constructor for empty constructor
    Teacher::Teacher() : LibUser(), BORROWED_LIMIT(10){}

    // Teachers to add books to the library's collection (getter method)
    bool Teacher::add_book_to_library(Library& library, Book* book) {
        if (library.insert(book)) {
            cout << "Teacher added the book titled '" << book->get_title() << "' to the library.\n";
            return true;
        } else {
            cout << "Failed to add the book titled '" << book->get_title() << "'. It may already exist.\n";
            return false;
        }
    }

    // Parameterized constructor for teacher
    Teacher::Teacher(string new_name, string new_user_id, int new_borrowed_count): LibUser(new_name, new_user_id, new_borrowed_count), BORROWED_LIMIT(10){};

    // Method which retrieves student borrow limit (getter method)
    int Teacher::get_borrowed_limit() const {
        return BORROWED_LIMIT; 
    }

    // Print method for teacher
    void Teacher::print() const{
        cout << "Teacher:" << endl;
        cout << "Name: " << get_name() << endl;
        cout << "User ID: " << get_user_id() << endl;
        cout << "Borrowed Limit: " << get_borrowed_limit() << endl;
        cout << "Borrowed books: " << get_borrowed_count() << endl;
        cout << "\n";
        }
