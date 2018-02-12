// exercise 5.7

/**
 *
 * Design a structure called Car that holds the following information about an automobile:
 * its make, as a string in a character array or in a string object and the year
 * it was built, as an integer. Write a program that asks the user how many cars to
 * catalog. The program should then use new to create a dynamic array of that many Car
 * structures. Next, it should prompt the user to input the make (which might consist
 * of more than one word) and year information for each structure. Note that this
 * requires some care because it alternates reading strings with numeric data (see
 * Chapter 4). Finally, it should display the contents of each structure. A sample run
 * should look something like the following:
 *
 * How many cars do you wish to catalog? 2
 *
 * Car #1:
 * Please enter the make: Hudson Hornet
 * Please enter the year made: 1952
 * Car #2:
 * Please enter the make: Kaiser
 * Please enter the year made: 1951
 *
 * Here is your collection:
 * 1952 Hudson Hornet
 * 1951 Kaiser
 *
 */

#include <iostream>
#include <string>

struct Car
{
    std::string make;
    unsigned year;
};

void setCarInformation(Car *, unsigned);
void displayCarInformation(Car *, unsigned);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "How many cars do you wish to catalog? ";
    unsigned amount;
    (cin >> amount).get();

    Car * cars = new Car[amount];
    cout << endl;
    setCarInformation(cars, amount);

    cout << "\nHere is your collection:\n";
    displayCarInformation(cars, amount);
    delete[] cars;

    return 0;
}

void setCarInformation(Car * cars, unsigned amount)
{
    using std::cin;
    using std::cout;

    for (unsigned i = 0u; i < amount; i++)
    {
        cout << "Car #" << i + 1u << ":\n"
                "Please enter the make: ";
        getline(cin, cars[i].make);

        cout << "Please enter the year made: ";
        (cin >> cars[i].year).get();
    }
}

void displayCarInformation(Car * cars, unsigned amount)
{
    for (unsigned i = 0u; i < amount; i++)
        std::cout << cars[i].year << " " << cars[i].make << std::endl;
}
