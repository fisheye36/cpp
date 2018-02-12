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
    using std::cin;
    using std::cout;

    cout << "Enter numbers. To stop, enter 0.\n"
            "Enter first number: ";
    int number;
    cin >> number;
    long long sum = 0LL;
    while (number)
    {
        sum += number;
        cout << "The cumulative sum of the entries is " << sum << ".\n\n"
                "Enter another number: ";
        cin >> number;
    }

    return 0;
}
