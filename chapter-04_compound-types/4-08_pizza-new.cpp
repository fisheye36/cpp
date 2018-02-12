// exercise 4.8

/**
 *
 * Do Programming Exercise 7 (4.7) but use new to allocate a structure instead of
 * declaring a structure variable. Also have the program request the pizza diameter before
 * it requests the pizza company name.
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

    Pizza * pizza = new Pizza;
    cout << "Enter pizza diameter in centimeters: ";
    (cin >> pizza->diameter).get();

    cout << "Enter pizza company name: ";
    getline(cin, pizza->company);

    cout << "Enter pizza weight in kilograms: ";
    cin >> pizza->weight;

    cout << "\nPizza \"" << pizza->company << "\"\n"
            "Diameter: " << pizza->diameter << " cm\n"
            "Weight: " << pizza->weight << " kg\n";
    delete pizza;

    return 0;
}
