// exercise 2.3

/**
 *
 * Write a C++ program that uses three user-defined functions (counting main() as
 * one) and produces the following output:
 *
 * Three blind mice
 * Trhee blind mice
 * See how they run
 * See how they run
 *
 * One function, called two times, should produce the first two lines, and the remaining
 * function, also called twice, should produce the remaining output.
 *
 */

#include <iostream>

void mice();
void run();

int main()
{
    mice();
    mice();
    run();
    run();

    return 0;
}

void mice()
{
    std::cout << "Three blind mice\n";
}

void run()
{
    std::cout << "See how they run\n";
}
