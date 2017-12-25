// exercise 6.8

/**
 *
 * Write a program that opens a text file, reads it character-by-character to the end of
 * the file and reports the number of characters in the file.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

unsigned long long countChars(std::string);

int main()
{
    using std::cout;

    cout << "Enter file name to open: ";
    std::string fileName;
    std::cin >> fileName;

    unsigned long long count = countChars(fileName);
    cout << count << ((count == 1uLL) ? " character" : " characters") << " read.\n";

    return 0;
}

unsigned long long countChars(std::string fileName)
{
    using std::cout;

    std::ifstream fileIn;
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
