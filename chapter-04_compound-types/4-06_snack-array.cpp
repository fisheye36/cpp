// exercise 4.6

/**
 *
 * The CandyBar structure contains three members, as described in Programming Exercise 5
 * (4.5). Write a program that creates an array of three CandyBar structures, initializes
 * them to values of your choice and then displays the contents of each structure.
 *
 */

#include <iostream>
#include <string>

struct CandyBar
{
    std::string brand;
    double weight;
    int calories;
};

void displaySnackInformation(CandyBar);

int main()
{
    using std::cout;
    using std::endl;

    CandyBar snacks[] =
    {
        { "Mars", 2.4, 320 },
        { "Twix", 2.6, 380 },
        { "Snickers", 3.2, 360 }
    };

    displaySnackInformation(snacks[0]);
    cout << endl;
    displaySnackInformation(snacks[1]);
    cout << endl;
    displaySnackInformation(snacks[2]);

    return 0;
}

void displaySnackInformation(CandyBar snack)
{
    std::cout << "Snack: " << snack.brand
              << "\nWeight: " << snack.weight
              << "\nCalories: " << snack.calories << std::endl;
}
