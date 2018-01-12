// exercise 7.6

/**
 *
 * Write a program that uses the following functions:
 *
 * fillArray() takes as arguments the name of an array of double values and an
 * array size. It prompts the user to enter double values to be entered in the array. It
 * ceases taking input when the array is full or when the user enters non-numeric
 * input and it returns the actual number of entries.
 *
 * showArray() takes as arguments the name of an array of double values and an
 * array size and displays the contents of the array.
 *
 * reverseArray() takes as arguments the name of an array of double values and an
 * array size and reverses the order of the values stored in the array.
 *
 * The program should use these functions to fill an array, show the array, reverse the
 * array, show the array, reverse all but the first and last elements of the array and then
 * show the array.
 *
 */

#include <iostream>

unsigned fillArray(double * arr, unsigned size);
void reverseArray(double * arr, unsigned size);
void showArray(const double * arr, unsigned size);
void swap(double * a, double * b);
void clearInput();

int main()
{
    using std::cout;

    const unsigned Size = 10u;

    cout << "Enter up to " << Size << " numbers. To stop, enter invalid number.\n";
    double numbers[Size];
    unsigned numbersRead = fillArray(numbers, Size);

    if (numbersRead > 1u)
    {
        cout << "\nArray contents:\n";
        showArray(numbers, numbersRead);

        cout << "\nReversed array:\n";
        reverseArray(numbers, numbersRead);
        showArray(numbers, numbersRead);

        cout << "\nReversed array (without first and last elements):\n";
        reverseArray(numbers + 1, numbersRead - 2);
        showArray(numbers, numbersRead);
    }

    return 0;
}

unsigned fillArray(double * arr, unsigned size)
{
    using std::cout;

    cout << "Number #1: ";
    unsigned i = 0u;
    while (i < size && std::cin >> arr[i])
    {
        clearInput();
        if (++i < size)
            cout << "Number #" << i + 1u << ": ";
    }

    return i;
}

void reverseArray(double * arr, unsigned size)
{
    double * end = arr + size;
    while (arr < --end)
        swap(arr++, end);
}

void showArray(const double * arr, unsigned size)
{
    using std::cout;

    cout << arr[0];
    for (unsigned i = 1u; i < size; i++)
        cout << ", " << arr[i];
    cout << std::endl;
}

void swap(double * a, double * b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void clearInput()
{
    while (std::cin.get() != '\n')
        continue;
}
