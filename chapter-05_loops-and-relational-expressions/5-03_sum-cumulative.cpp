// exercise 5.3

/**
 *
 * Write a program that asks the user to type in numbers. After each entry, the program
 * should report the cumulative sum of the entries to date. The program should
 * terminate when the user enters 0.
 *
 */

#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter a number: ";
    int number;
    cin >> number;

    long long sum = 0LL;
    while (number)
    {
        sum += number;
        cout << "The cumulative sum of the entries is " << sum << ".\n"
                "Enter another number (0 to quit): ";
        cin >> number;
    }

    return 0;
}
