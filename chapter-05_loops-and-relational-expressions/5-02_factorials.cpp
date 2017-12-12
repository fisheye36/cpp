// exercise 5.2

/**
 *
 * Redo Listing 5.4 using a type array object instead of a built-in array and type
 * long double instead of long long. Find the value of 100!
 *
 */

#include <iostream>
#include <array>

int main()
{
    const int MaxFactorial = 100;
    const int Size = MaxFactorial + 1;

    std::array<long double, Size> factorials;
    factorials[0] = factorials[1] = 1.0;
    for (int i = 2; i < Size; i++)
        factorials[i] = i * factorials[i - 1];

    for (int i = 0; i < Size; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;

    return 0;
}
