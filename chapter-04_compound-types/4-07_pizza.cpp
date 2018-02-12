// exercise 4.7

/**
 *
 * William Wingate runs a pizza-analysis service. For each pizza, he needs to record
 * the following information:
 * - the name of the pizza company, which can consist of more than one word,
 * - the diameter of the pizza,
 * - the weight of the pizza.
 *
 * Devise a structure that can hold this information and write a program that uses a
 * structure variable of that type. The program should ask the user to enter each of the
 * preceding items of information, and then the program should display that information
 * Use cin (or its methods) and cout.
 *
 */

#include <iostream>
#include <string>

struct Pizza
{
    std::string company;
    unsigned diameter;
    double weight;
};

int main()
{
    using std::cin;
    using std::cout;
    using std::getline;

    Pizza pizza;
    cout << "Enter pizza company name: ";
    getline(cin, pizza.company);

    cout << "Enter pizza diameter in centimeters: ";
    cin >> pizza.diameter;

    cout << "Enter pizza weight in kilograms: ";
    cin >> pizza.weight;

    cout << "\nPizza \"" << pizza.company << "\"\n"
            "Diameter: " << pizza.diameter << " cm\n"
            "Weight: " << pizza.weight << " kg\n";

    return 0;
}
