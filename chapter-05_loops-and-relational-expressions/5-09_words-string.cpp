// exercise 5.9

/**
 *
 * Write a program that matches the description of the program in Programming
 * Exercise 8 (5.8), but use a string class object instead of an array. Include the string
 * header file and use a relational operator to make the comparison test.
 *
 */

#include <iostream>
#include <string>

int main()
{
    using std::cout;
    using std::cin;
    using std::string;

    const string ExitWord = "done";

    cout << "Enter words (to stop, type the word done):\n";
    string word;
    cin >> word;

    unsigned amount = 0u;
    while (word != ExitWord)
    {
        cin >> word;
        amount++;
    }

    cout << "You entered a total of " << amount << " words.\n";

    return 0;
}
