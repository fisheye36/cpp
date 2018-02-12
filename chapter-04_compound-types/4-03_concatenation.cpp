// exercise 4.3

/**
 *
 * Write a program that asks the user to enter his or her first name and then last
 * name, and that then constructs, stores, and displays a third string, consisting of the
 * user’s last name followed by a comma, a space, and first name. Use char arrays and
 * functions from the cstring header file. A sample run could look like this:
 *
 * Enter your first name: Flip
 * Enter your last name: Fleming
 * Here’s the information in a single string: Fleming, Flip
 *
 */

#include <iostream>
#include <cstring> // strcat(), strcpy(), strlen()

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strcat;
    using std::strcpy;
    using std::strlen;

    const unsigned MaxSize = 40u;

    cout << "Enter your first name: ";
    char firstName[MaxSize];
    cin.getline(firstName, MaxSize);

    cout << "Enter your last name: ";
    char lastName[MaxSize];
    cin.getline(lastName, MaxSize);

    unsigned totalSize = strlen(firstName) + strlen(lastName) + 3u;
    char * concString = new char[totalSize];

    strcpy(concString, lastName);
    strcat(concString, ", ");
    strcat(concString, firstName);
    cout << "Here's the information in a single string: " << concString << endl;

    return 0;
}
