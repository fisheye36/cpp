// exercise 7.1

/**
 *
 * Write a program that repeatedly asks the user to enter pairs of numbers until at
 * least one of the pair is 0. For each pair, the program should use a function to
 * calculate the harmonic mean of the numbers. The function should return the answer to
 * main(), which should report the result. The harmonic mean of the numbers is the
 * inverse of the average of the inverses and can be calculated as follows:
 *
 * harmonic mean = 2.0 * x * y / (x + y)
 *
 */

#include <iostream>

double harmonic(double a, double b);
double readNumber(const std::string * prompt);
void clearInput();

int main()
{
    using std::cout;
    using std::string;

    const string firstPrompt = "Enter first number: ";
    const string secondPrompt = "Enter second number: ";

    cout << "Enter pairs of numbers. To stop, enter 0 as either number.\n\n"
            "First pair:\n";
    double first;
    double second;
    while ((first = readNumber(&firstPrompt)) && (second = readNumber(&secondPrompt)))
        cout << "Harmonic mean: " << harmonic(first, second) << "\n\nNext pair:\n";

    return 0;
}

double harmonic(double a, double b)
{
    return 2.0 * a * b / (a + b);
}

double readNumber(const std::string * prompt)
{
    using std::cout;

    cout << *prompt;
    double value;
    while (!(std::cin >> value))
    {
        clearInput();
        cout << "Try again: ";
    }
    clearInput();

    return value;
}

void clearInput()
{
    using std::cin;

    cin.clear();
    while (cin.get() != '\n')
        continue;
}
