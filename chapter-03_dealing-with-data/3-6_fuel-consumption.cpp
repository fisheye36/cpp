// exercise 3.6

/**
 *
 * Write a program that asks how many miles you have driven and how many gallons
 * of gasoline you have used and then reports the miles per gallon your car has gotten.
 * Or, if you prefer, the program can request distance in kilometers and petrol in liters
 * and then report the result European style, in liters per 100 kilometers.
 *
 */

#include <iostream>

double fuelConsumption(unsigned, double);

int main()
{
    using std::cin;
    using std::cout;

    cout << "Enter distance in kilometers: ";
    unsigned distance;
    cin >> distance;

    cout << "Now, enter the amount of fuel consumed in liters: ";
    double fuel;
    cin >> fuel;

    cout << "Your car consumes " << fuelConsumption(distance, fuel)
         << " liters per 100 kilometers.\n";

    return 0;
}

double fuelConsumption(unsigned distance, double fuel)
{
    return fuel / distance * 100.0;
}
