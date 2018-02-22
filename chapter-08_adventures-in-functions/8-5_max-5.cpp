// exercise 8.5

/**
 *
 * Write a template function max5() that takes as its argument an array of five items
 * of type T and returns the largest item in the array. (Because the size is fixed, it can
 * be hard-coded into the loop instead of being passed as an argument.) Test it in a
 * program that uses the function with an array of five int values and an array of five
 * double values.
 *
 */

#include <iostream>

template <typename T>
    inline void fillArray(T * arr, unsigned size);
template <typename T>
    T max5(const T * arr);

template <typename T>
    void readValue(T & value);
inline void clearInput();

const unsigned Size = 5u;

int main()
{
    using std::cout;
    using std::endl;

    cout << "Enter " << Size << " integer values.\n";
    int intArr[Size];
    fillArray(intArr, Size);
    cout << "Max value: " << max5(intArr) << endl;

    cout << "\nEnter " << Size << " double values.\n";
    double doubleArr[Size];
    fillArray(doubleArr, Size);
    cout << "Max value: " << max5(doubleArr) << endl;

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

template <typename T>
T max5(const T * arr)
{
    T max = arr[0];
    for (unsigned i = 1u; i < Size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
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

void clearInput()
{
    using std::cin;

    cin.clear();
    while (cin.get() != '\n')
        continue;
}
