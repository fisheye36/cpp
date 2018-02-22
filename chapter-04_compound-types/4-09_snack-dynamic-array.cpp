// exercise 4.9

/**
 *
 * Do Programming Exercise 6 (4.6), but instead of declaring an array of three CandyBar
 * structures, use new to allocate the array dynamically.
 *
 */

#include <iostream>
#include <string>

struct CandyBar
{
    std::string brand;
    double weight;
    unsigned calories;
};

void setSnackInformation(CandyBar *, std::string, double, unsigned);
void displaySnackInformation(CandyBar);

int main()
{
    using std::cout;
    using std::endl;

    CandyBar * snacks = new CandyBar[3];
    setSnackInformation(snacks, "Mars", 2.4, 320u);
    setSnackInformation(snacks + 1, "Twix", 2.6, 380u);
    setSnackInformation(snacks + 2, "Snickers", 3.2, 360u);

    displaySnackInformation(snacks[0]);
    cout << endl;
    displaySnackInformation(snacks[1]);
    cout << endl;
    displaySnackInformation(snacks[2]);
    delete[] snacks;

    return 0;
}

void setSnackInformation(CandyBar * snack, std::string brand, double weight,
                         unsigned calories)
{
    snack->brand = brand;
    snack->weight = weight;
    snack->calories = calories;
}

void displaySnackInformation(CandyBar snack)
{
    std::cout << "Snack: " << snack.brand
              << "\nWeight: " << snack.weight
              << "\nCalories: " << snack.calories << std::endl;
}
