// exercise 6.7

/**
 *
 * Write a program that reads input a word at a time until a lone q is entered. The
 * program should then report the number of words that began with vowels, the number
 * that began with consonants and the number that fit neither of those categories.
 * One approach is to use isalpha() to discriminate between words beginning with
 * letters and those that don’t and then use an if or switch statement to further identify
 * those passing the isalpha() test that begin with vowels. A sample run might
 * look like this:
 *
 * Enter words (q to quit):
 * The 12 awesome oxen ambled
 * quietly across 15 meters of lawn. q
 *
 * 5 words beginning with vowels.
 * 4 words beginning with consonants.
 * 2 others.
 *
 */

#include <iostream>
#include <string>
#include <cctype>

bool isVowel(char);

int main()
{
    using std::cout;
    using std::string;

    const string ExitWord = "q";

    cout << "Enter words (" << ExitWord << " to quit):\n";
    string word;
    unsigned vowels = 0u;
    unsigned consonants = 0u;
    unsigned others = 0u;
    while (std::cin >> word && word != ExitWord)
    {
        if (isalpha(word[0]))
        {
            if (isVowel(word[0]))
                vowels++;
            else
                consonants++;
        }
        else
        {
            others++;
        }
    }

    cout << std::endl << vowels << ((vowels == 1u) ? " word" : " words")
         << " beginning with vowels.\n"
         << consonants << ((consonants == 1u) ? " word" : " words")
         << " beginning with consonants.\n"
         << others << ((others == 1u) ? " other.\n" : " others.\n");

    return 0;
}

bool isVowel(char ch)
{
    const char Vowels[] = { 'a', 'e', 'i', 'o', 'u' };
    const unsigned Amount = sizeof Vowels;

    ch = tolower(ch);
    for (unsigned i = 0u; i < Amount; i++)
    {
        if (ch == Vowels[i])
            return true;
    }

    return false;
}
