// exercise 4.1

/**
 *
 * Write a C++ program that requests and displays information as shown in the following
 * example of output:
 *
 * What is your first name? Betty Sue
 * What is your last name? Yewe
 * What letter grade do you deserve? B
 * What is your age? 22
 *
 * Name: Yewe, Betty Sue
 * Grade: C
 * Age: 22
 *
 * Note that the program should be able to accept first names that comprise more
 * than one word. Also note that the program adjusts the grade downward - that is, up
 * one letter. Assume that the user requests an A, a B, or a C so that you don’t have to
 * worry about the gap between a D and an F.
 *
 */

#include <iostream>
#include <string>

struct Student
{
    std::string firstName;
    std::string lastName;
    char grade;
    int age;
};

int main()
{
    using std::cout;
    using std::cin;

    Student user;
    cout << "What is your first name? ";
    getline(cin, user.firstName);

    cout << "What is your last name? ";
    getline(cin, user.lastName);

    cout << "What letter grade do you deserve? ";
    cin >> user.grade;

    cout << "What is your age? ";
    cin >> user.age;

    cout << "\nName: " << user.lastName << ", " << user.firstName
         << "\nGrade: " << char(user.grade + 1)
         << "\nAge: " << user.age << std::endl;

    return 0;
}
