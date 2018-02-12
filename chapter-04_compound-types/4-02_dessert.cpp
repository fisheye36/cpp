// exercise 4.2

/**
 *
 * Rewrite Listing 4.4, using the C++ string class instead of char arrays.
 *
 */

#include <iostream>
#include <string>

int main()
{
    using std::cin;
    using std::cout;
    using std::getline;
    using std::string;

    cout << "Enter your name: ";
    string name;
    getline(cin, name);

    cout << "Enter your favorite dessert: ";
    string dessert;
    getline(cin, dessert);

    cout << "I have some delicious " << dessert << " for you, " << name << ".\n";

    return 0;
}
