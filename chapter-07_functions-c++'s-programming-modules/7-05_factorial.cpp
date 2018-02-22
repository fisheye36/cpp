// exercise 7.5

/**
 *
 * Define a recursive function that takes an integer argument and returns the factorial
 * of that argument. Recall that 3 factorial, written 3!, equals 3 * 2! and so on, with 0!
 * defined as 1. In general, if n is greater than zero, n! = n * (n - 1)!. Test your
 * function in a program that uses a loop to allow the user to enter various values for
 * which the program reports the factorial.
*
*/

#include <iostream>

unsigned long long factorial(unsigned long long n);
void clearInput();

int main()
{
    using std::cin;
    using std::cout;

    cout << "Enter a number to get the factorial. To stop, enter invalid number.\n"
            "Enter first number: ";
    unsigned number;
    while (cin >> number)
    {
        clearInput();
        cout << number << "! = " << factorial(number) << "\n\nEnter next number: ";
    }

    return 0;
}

unsigned long long factorial(unsigned long long n)
{
    if (n < 2uLL)
        return 1uLL;

    return n * factorial(n - 1uLL);
}

void clearInput()
{
    while (std::cin.get() != '\n')
        continue;
}
