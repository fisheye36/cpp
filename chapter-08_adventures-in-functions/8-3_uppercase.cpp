// exercise 8.3

/**
 *
 * Write a function that takes a reference to a string object as its parameter and that
 * converts the contents of the string to uppercase. Use the toupper() function
 * described in Table 6.4 of Chapter 6. Write a program that uses a loop which allows
 * you to test the function with different input. A sample run might look like this:
 *
 * Enter a string (q to quit): go away
 * GO AWAY
 *
 * Next string: good grief!
 * GOOD GRIEF!
 *
 * Next string: q
 *
 * Bye!
 *
 */

#include <iostream>
#include <string>
#include <cctype>

const std::string & uppercase(std::string & str);

int main()
{
    using std::cout;
    using std::cin;
    using std::string;

    const string ExitWord = "q";

    cout << "Enter a string (" << ExitWord << " to quit): ";
    string str;
    getline(cin, str);
    while (str != ExitWord)
    {
        cout << uppercase(str) << "\n\nNext string: ";
        getline(cin, str);
    }

    cout << "\nBye!\n";

    return 0;
}

const std::string & uppercase(std::string & str)
{
    const unsigned Size = str.size();
    for (unsigned i = 0u; i < Size; i++)
        str[i] = toupper(str[i]);

    return str;
}
