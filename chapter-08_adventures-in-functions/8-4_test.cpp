// exercise 8.4

/**
 *
 * The following is a program skeleton:
 *
 * #include <iostream>
 * #include <cstring> // for strlen(), strcpy()
 *
 * struct Stringy
 * {
 *     char * str;   // points to a string
 *     unsigned len; // lenght of string (not counting '\0')
 * };
 *
 * // prototypes for set(), show() and unset() go here
 *
 * int main()
 * {
 *     Stringy beany;
 *     char testing[] = "Reality isn't what it used to be.";
 *
 *     set(beany, testing); // first argument is a reference,
 *                          // allocates space to hold copy of testing,
 *                          // sets str member of beany to point to the
 *                          // new block, copies testing to new block
 *                          // and sets len member of beany
 *
 *     show(beany);     // prints member string once
 *     show(beany, 2u); // prints member string twice
 *     unset(beany);    // frees memory
 *
 *     testing[0] = 'D';
 *     testing[1] = 'u';
 *
 *     show(testing);     // prints testing string once
 *     show(testing, 3u); // prints testing string thirce
 *
 *     show("\nDone!");
 *
 *     return 0;
 * }
 *
 * Complete this skeleton by providing the described functions and prototypes. Note
 * that there should be two show() functions, each using default arguments. Use
 * const arguments when appropriate. Note that set() should use new to allocate
 * sufficient space to hold the designated string. The techniques used here are similar
 * to those used in designing and implementing classes. (You might have to alter the
 * header filenames depending on your compiler.)
 *
 */

#include <iostream>
#include <cstring>

struct Stringy
{
    char * str;
    unsigned len;
};

void set(Stringy & stringy, const char * str);
void unset(Stringy & stringy);
void show(const Stringy & stringy, unsigned times = 1u);
void show(const char * str, unsigned times = 1u);

int main()
{
    Stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);

    show(beany);
    show(beany, 2u);
    unset(beany);

    testing[0] = 'D';
    testing[1] = 'u';

    show(testing);
    show(testing, 3u);

    show("\nDone!");

    return 0;
}

void set(Stringy & stringy, const char * str)
{
    stringy.len = strlen(str);
    stringy.str = new char[stringy.len + 1u];
    strcpy(stringy.str, str);
}

void unset(Stringy & stringy)
{
    delete[] stringy.str;
}

void show(const Stringy & stringy, unsigned times)
{
    for (unsigned i = 0u; i < times; i++)
        std::cout << stringy.str << std::endl;
}

void show(const char * str, unsigned times)
{
    for (unsigned i = 0u; i < times; i++)
        std::cout << str << std::endl;
}
