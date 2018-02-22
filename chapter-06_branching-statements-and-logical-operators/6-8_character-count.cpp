// exercise 6.8

/**
 *
 * Write a program that opens a text file, reads it character-by-character to the end of
 * the file and reports the number of characters in the file.
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // EXIT_FAILURE, exit()

unsigned long long countChars(std::string);

int main()
{
    using std::cin;
    using std::cout;
    using std::string;

    cout << "Enter file name to open: ";
    string fileName;
    cin >> fileName;

    unsigned long long count = countChars(fileName);
    cout << count << ((count == 1uLL) ? " character" : " characters") << " read.\n";

    return 0;
}

unsigned long long countChars(std::string fileName)
{
    using std::cout;
    using std::exit;
    using std::ifstream;

    ifstream fileIn;
    fileIn.open(fileName);
    if (!fileIn.is_open())
    {
        cout << "Could not open file \"" << fileName << "\".\n";
        exit(EXIT_FAILURE);
    }

    unsigned long long count = 0uLL;
    while (fileIn.get() != EOF && fileIn)
        count++;

    if (fileIn.eof())
        cout << "Input terminated (EOF reached).\n";
    else
        cout << "Input terminated (unknown reason).\n";
    fileIn.close();

    return count;
}
