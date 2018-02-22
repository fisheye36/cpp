// exercise 7.10

/**
 *
 * Design a function calculate() that takes two type double values and a pointer to
 * a function that takes two double arguments and returns a double. The
 * calculate() function should also be type double and it should return the value
 * that the pointed-to function calculates, using the double arguments to
 * calculate(). For example, suppose you have this definition for the add()
 * function:
 *
 * double add(double x, double y)
 * {
 *     return x + y;
 * }
 *
 * Then, the function call in the following would cause calculate() to pass the values
 * 2.5 and 10.4 to the add() function and then return the add() return value
 * (12.9):
 *
 * double q = calculate(2.5, 10.4, add);
 *
 * Use these functions and at least one additional function in the add() mold in a
 * program. The program should use a loop that allows the user to enter pairs of numbers.
 * For each pair, use calculate() to invoke add() and at least one other function.
 * If you are feeling adventurous, try creating an array of pointers to add()-style
 * functions and use a loop to successively apply calculate() to a series of functions
 * by using these pointers. Hint: here’s how to declare such an array of three pointers:
 *
 * double (*pf[3])(double, double);
 *
 * You can initialize such an array by using the usual array initialization syntax and
 * function names as addresses.
 *
 */

#include <iostream>

struct Pair
{
    double x;
    double y;
};

double calculate(double x, double y, double (* calc)(double, double));
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

bool readPair(Pair * pair);
void clearInput();

int main()
{
    using std::cout;
    using std::endl;

    double (* functions[])(double, double) = { add, subtract, multiply, divide };
    const unsigned FunAmount = sizeof (functions) / sizeof (double (*)(double, double));

    Pair pair;
    cout << "Enter pairs of numbers. To stop, enter invalid number.\n\n"
            "First pair:\n";
    while (readPair(&pair))
    {
        cout << endl;
        for (unsigned i = 0u; i < FunAmount; i++)
        {
            double result = calculate(pair.x, pair.y, functions[i]);
            cout << result << endl;
        }
        cout << "\nEnter next pair:\n";
    }

    return 0;
}

double calculate(double x, double y, double (* calc)(double, double))
{
    return calc(x, y);
}

double add(double x, double y)
{
    std::cout << x << " + " << y << " = ";
    return x + y;
}

double subtract(double x, double y)
{
    std::cout << x << " - " << y << " = ";
    return x - y;
}

double multiply(double x, double y)
{
    std::cout << x << " * " << y << " = ";
    return x * y;
}

double divide(double x, double y)
{
    std::cout << x << " / " << y << " = ";
    return x / y;
}

bool readPair(Pair * pair)
{
    using std::cin;
    using std::cout;

    cout << "Enter first number: ";
    if (!(cin >> pair->x))
        return false;
    clearInput();

    cout << "Enter second number: ";
    if (!(cin >> pair->y))
        return false;
    clearInput();

    return true;
}

void clearInput()
{
    while (std::cin.get() != '\n')
        continue;
}
