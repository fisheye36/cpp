// exercise 8.1

/**
 *
 * Write a function that normally takes one argument, the address of a string, and
 * prints that string once. However, if a second, type int argument is provided and is
 * nonzero, the function should print the string a number of times equal to the number
 * of times that function has been called at that point. (Note that the number of
 * times the string is printed is not equal to the value of the second argument; it is
 * equal to the number of times the function has been called.) Yes, this is a silly function,
 * but it makes you use some of the techniques discussed in this chapter. Use the
 * function in a simple program that demonstrates how the function works.
 *
 */

#include <iostream>

void print(const char * str, int repeat = 0);
int readNumber();
void clearInput();

unsigned calls = 0u;

int main()
{
    using std::cout;

    const unsigned Size = 80u;

    cout << "Enter strings of text. To stop, enter an empty string.\n\n"
            "First string: ";
    char str[Size];
    while (std::cin.get(str, Size))
    {
        clearInput();
        cout << "Enter a number: ";
        int number = readNumber();

        cout << "\nPrinting your string:\n";
        print(str, number);
        cout << "\nEnter another string: ";
    }

    return 0;
}

void print(const char * str, int repeat)
{
    calls++;
    unsigned times = (repeat) ? calls : 1u;
    for (unsigned i = 0; i < times; i++)
        std::cout << str << std::endl;
}

int readNumber()
{
    int number;
    while (!(std::cin >> number))
    {
        clearInput();
        std::cout << "Try again: ";
    }
    clearInput();

    return number;
}

void clearInput()
{
    using std::cin;

    cin.clear();
    while (cin.get() != '\n')
        continue;
}
