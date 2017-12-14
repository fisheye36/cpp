// exercise 3.1

/**
 *
 * Write a short program that asks for your height in integer inches and then converts
 * your height to feet and inches. Have the program use the underscore character to
 * indicate where to type the response. Also use a const symbolic constant to represent
 * the conversion factor.
 *
 */

#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    const unsigned InchesInFoot = 12u;

    cout << "Enter your height in inches: __\b\b";
    unsigned height;
    cin >> height;

    unsigned feet = height / InchesInFoot;
    unsigned inches = height % InchesInFoot;
    cout << "Your height is " << feet << " feet, " << inches << " inches.\n";

    return 0;
}
