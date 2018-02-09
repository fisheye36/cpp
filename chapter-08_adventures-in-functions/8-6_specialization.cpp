// exercise 8.6

/**
 *
 * Write a template function maxN() that takes as its arguments an array of items of
 * type T and an integer representing the number of elements in the array and that
 * returns the largest item in the array. Test it in a program that uses the function
 * template with an array of six int values and an array of four double values. The program
 * should also include a specialization that takes an array of pointers-to-char as
 * an argument and the number of pointers as a second argument and that returns the
 * address of the longest string. If multiple strings are tied for having the longest
 * length, the function should return the address of the first one tied for longest. Test
 * the specialization with an array of five string pointers.
 *
 */

#include <iostream>
#include <cstring>

template <typename T>
    void fillArray(T * arr, unsigned size);
template <>
    void fillArray(char ** arr, unsigned size);
void freeArray(char ** arr, unsigned size);
template <typename T>
    T maxN(const T * arr, unsigned size);
template <>
    char * maxN(char * const * arr, unsigned size);

template <typename T>
    void readValue(T & value);
void readString(char * & str);
void clearInput();

int main()
{
    using std::cout;
    using std::endl;

    const unsigned SizeInt = 6u;
    const unsigned SizeDouble = 4u;
    const unsigned SizeStrings = 5u;

    cout << "Enter " << SizeInt << " integer values.\n";
    int intArr[SizeInt];
    fillArray(intArr, SizeInt);
    cout << "Max value: " << maxN(intArr, SizeInt) << endl;

    cout << "\nEnter " << SizeDouble << " double values.\n";
    double doubleArr[SizeDouble];
    fillArray(doubleArr, SizeDouble);
    cout << "Max value: " << maxN(doubleArr, SizeDouble) << endl;

    cout << "\nEnter " << SizeStrings << " strings.\n";
    char * strArr[SizeStrings];
    fillArray(strArr, SizeStrings);
    cout << "Longest string: " << maxN(strArr, SizeStrings) << endl;
    freeArray(strArr, SizeStrings);

    return 0;
}

template <typename T>
void fillArray(T * arr, unsigned size)
{
    for (unsigned i = 0u; i < size; i++)
    {
        std::cout << "Value #" << i + 1u << ": ";
        readValue(arr[i]);
    }
}

template <>
void fillArray(char ** arr, unsigned size)
{
    for (unsigned i = 0u; i < size; i++)
    {
        std::cout << "String #" << i + 1u << ": ";
        readString(arr[i]);
    }
}

void freeArray(char ** arr, unsigned size)
{
    for (unsigned i = 0u; i < size; i++)
        delete[] arr[i];
}

template <typename T>
T maxN(const T * arr, unsigned size)
{
    T max = arr[0];
    for (unsigned i = 1u; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

template <>
char * maxN(char * const * arr, unsigned size)
{
    char * maxStr = arr[0];
    unsigned maxLen = strlen(maxStr);
    for (unsigned i = 1u; i < size; i++)
    {
        if (strlen(arr[i]) > maxLen)
        {
            maxStr = arr[i];
            maxLen = strlen(maxStr);
        }
    }

    return maxStr;
}

template <typename T>
void readValue(T & value)
{
    while (!(std::cin >> value))
    {
        clearInput();
        std::cout << "Try again: ";
    }
    clearInput();
}

void readString(char * & str)
{
    const unsigned MaxSize = 40u;

    char temp[MaxSize];
    while (!std::cin.get(temp, MaxSize))
    {
        clearInput();
        std::cout << "Try again: ";
    }
    clearInput();

    str = new char[strlen(temp) + 1];
    strcpy(str, temp);
}

void clearInput()
{
    using std::cin;

    cin.clear();
    while (cin.get() != '\n')
        continue;
}
