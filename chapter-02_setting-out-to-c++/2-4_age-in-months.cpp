// exercise 2.4

/**
 *
 * Write a program that asks the user to enter his or her age. The program then should
 * display the age in months:
 *
 * Enter your age: 29
 * Your age in months is 348.
 *
 */

#include <iostream>

int ageInMonths(int);

int main()
{
    using std::cout;

    cout << "Enter your age: ";
    int age;
    std::cin >> age;
    cout << "Your age in months is " << ageInMonths(age) << ".\n";

    return 0;
}

int ageInMonths(int age)
{
    return age * 12;
}
