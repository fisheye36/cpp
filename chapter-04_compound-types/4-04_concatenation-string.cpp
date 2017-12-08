// exercise 4.4

/**
 *
 * Write a program that asks the user to enter his or her first name and then last
 * name, and that then constructs, stores, and displays a third string, consisting of the
 * user’s last name followed by a comma, a space, and first name. Use string objects
 * and methods from the string header file. A sample run could look like this:
 *
 * Enter your first name: Flip
 * Enter your last name: Fleming
 * Here’s the information in a single string: Fleming, Flip
 *
 */

#include <iostream>
#include <string>

int main()
{
    using std::cout;
    using std::cin;
    using std::string;

    cout << "Enter your first name: ";
    string firstName;
    getline(cin, firstName);

    cout << "Enter your last name: ";
    string lastName;
    getline(cin, lastName);

    string concString = lastName + ", " + firstName;
    cout << "Here's the information in a single string: " << concString << std::endl;

    return 0;
}
