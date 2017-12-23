// exercise 6.1

/**
 *
 * Write a program that reads keyboard input to the @ symbol and that echoes the
 * input except for digits, converting each uppercase character to lowercase and vice
 * versa. (Don’t forget the cctype family.)
 *
 */

#include <iostream>
#include <cctype>

int main()
{
    using std::cout;

    const char Stop = '@';

    cout << "Enter text (to stop, enter " << Stop << "):\n";
    char ch;
    bool emptyLine = true;
    while (std::cin.get(ch) && ch != Stop)
    {
        emptyLine = (ch == '\n');
        if (!isdigit(ch))
        {
            if (islower(ch))
                cout << char(toupper(ch));
            else
                cout << char(tolower(ch));
        }
    }

    if (!emptyLine)
        cout << std::endl;

    return 0;
}
