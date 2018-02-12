// exercise 5.8

/**
 *
 * Write a program that uses an array of char and a loop to read one word at a time
 * until the word done is entered. The program should then report the number of
 * words entered (not counting done). A sample run could look like this:
 *
 * Enter words (to stop, type the word done):
 * anteater birthday category dumpster
 * envy finagle geometry done for sure
 * You entered a total of 7 words.
 *
 * You should include the cstring header file and use the strcmp() function to
 * make the comparison test.
 *
 */

#include <iostream>
#include <cstring> // strcmp()

int main()
{
    using std::cin;
    using std::cout;
    using std::strcmp;

    const unsigned MaxSize = 40u;
    const char * ExitWord = "done";

    cout << "Enter words (to stop, type the word " << ExitWord << "):\n";
    char word[MaxSize];
    cin >> word;
    unsigned amount = 0u;
    while (strcmp(word, ExitWord))
    {
        amount++;
        cin >> word;
    }

    cout << "You entered a total of " << amount << " words.\n";

    return 0;
}
