// exercise 8.2

/**
 *
 * The CandyBar structure contains three members. The first member holds the brand
 * name of a candy bar. The second member holds the weight (which may have a fractional
 * part) of the candy bar, and the third member holds the number of calories
 * (an integer value) in the candy bar. Write a program that uses a function that takes
 * as arguments a reference to CandyBar, a pointer-to-char, a double and an unsigned int,
 * and uses the last three values to set the corresponding members of the structure. The
 * last three arguments should have default values of “Millennium Munch”, 2.85 and 350.
 * Also the program should use a function that takes a reference to a CandyBar as an
 * argument and displays the contents of the structure. Use const where appropriate.
 *
 */

#include <iostream>
#include <cstring> // strncpy()

const unsigned Size = 40u;

struct CandyBar
{
    char brand[Size];
    double weight;
    unsigned calories;
};

void setCandyBar(CandyBar & candyBar, const char * brand = "Millennium Munch",
                 double weight = 2.85, unsigned calories = 350u);
inline void display(const CandyBar & candyBar);

int main()
{
    using std::cout;

    const char * Brand = "Mars";
    const double Weight = 2.4;
    const unsigned Calories = 320u;

    CandyBar candyBar;
    setCandyBar(candyBar);
    cout << "Using default values:\n\n";
    display(candyBar);

    setCandyBar(candyBar, Brand, Weight, Calories);
    cout << "\nUsing explicit values:\n\n";
    display(candyBar);

    return 0;
}

void setCandyBar(CandyBar & candyBar, const char * brand, double weight,
                 unsigned calories)
{
    std::strncpy(candyBar.brand, brand, Size - 1u);
    candyBar.brand[Size] = '\0';
    candyBar.weight = weight;
    candyBar.calories = calories;
}

void display(const CandyBar & candyBar)
{
    std::cout << "Snack: " << candyBar.brand
              << "\nWeight: " << candyBar.weight
              << "\nCalories: " << candyBar.calories << std::endl;
}
