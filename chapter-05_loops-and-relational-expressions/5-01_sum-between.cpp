// exercise 5.1

/**
 *
 * Write a program that requests the user to enter two integers. The program should
 * then calculate and report the sum of all the integers between and including the two
 * integers. At this point, assume that the smaller integer is entered first. For example,
 * if the user enters 2 and 9, the program should report that the sum of all the integers
 * from 2 through 9 is 44.
 *
 */

#include <iostream>

long long sumBetween(int, int);

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter first number: ";
    int from;
    cin >> from;

    cout << "Enter second number: ";
    int to;
    cin >> to;

    cout << "Sum of all the integers from " << from << " to " << to
         << " is " << sumBetween(from, to) << ".\n";

    return 0;
}

long long sumBetween(int from, int to)
{
    long long sum = 0;
    for (long long i = from; i <= to; i++)
        sum += i;

    return sum;
}
