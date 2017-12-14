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
    const unsigned MaxFactorial = 100u;
    const unsigned Size = MaxFactorial + 1u;

    std::array<long double, Size> factorials;
    factorials[0] = factorials[1] = 1.0;
    for (unsigned i = 2u; i < Size; i++)
        factorials[i] = i * factorials[i - 1];

    for (unsigned i = 0u; i < Size; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;

    return 0;
}
