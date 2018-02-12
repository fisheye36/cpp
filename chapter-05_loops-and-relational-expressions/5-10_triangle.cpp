// exercise 5.10

/**
 *
 * Write a program using nested loops that asks the user to enter a value for the
 * number of rows to display. It should then display that many rows of asterisks, with
 * one asterisk in the first row, two in the second row and so on. For each row, the
 * asterisks are preceded by the number of periods needed to make all the rows
 * display a total number of characters equal to the number of rows. A sample run
 * would look like this:
 *
 * Enter number of rows: 5
 * ....*
 * ...**
 * ..***
 * .****
 * *****
 *
 */

#include <iostream>

void displayTriangle(unsigned, char, char);

int main()
{
    const char fill = '.';
    const char print = '*';

    std::cout << "Enter number of rows: ";
    unsigned rows;
    std::cin >> rows;
    displayTriangle(rows, fill, print);

    return 0;
}

void displayTriangle(unsigned rows, char fill, char print)
{
    using std::cout;
    using std::endl;

    for (unsigned i = 1u; i <= rows; i++)
    {
        for (unsigned j = 1u; j <= rows - i; j++)
            cout << fill;
        for (unsigned j = rows - i + 1u; j <= rows; j++)
            cout << print;
        cout << endl;
    }
}
