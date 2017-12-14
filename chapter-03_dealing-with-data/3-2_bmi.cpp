// exercise 3.2

/**
 *
 * Write a short program that asks for your height in feet and inches and your weight
 * in pounds. (Use three variables to store the information.) Have the program report
 * your body mass index (BMI). To calculate the BMI, first convert your height in feet
 * and inches to your height in inches (1 foot = 12 inches). Then convert your height
 * in inches to your height in meters by multiplying by 0.0254. Then convert your
 * weight in pounds into your mass in kilograms by dividing by 2.2. Finally, compute
 * your BMI by dividing your mass in kilograms by the square of your height in
 * meters. Use symbolic constants to represent the various conversion factors.
 *
 */

#include <iostream>

double feetAndInchesToMeters(unsigned, unsigned);
double poundsToKilograms(unsigned);
double bmi(double, double);

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter your height in feet and inches:\nFeet: ";
    unsigned feet;
    cin >> feet;

    cout << "Inches: ";
    unsigned inches;
    cin >> inches;

    cout << "Now, enter your weight in pounds: ";
    unsigned pounds;
    cin >> pounds;

    double heightMeters = feetAndInchesToMeters(feet, inches);
    double weightKilograms = poundsToKilograms(pounds);
    cout << "With a height of " << heightMeters << " m and a weight of " << weightKilograms
         << " kg your BMI is " << bmi(weightKilograms, heightMeters) << ".\n";

    return 0;
}

double feetAndInchesToMeters(unsigned feet, unsigned inches)
{
    const unsigned InchesInFoot = 12u;
    const double InchToMeter = 0.0254;

    return (feet * InchesInFoot + inches) * InchToMeter;
}

double poundsToKilograms(unsigned pounds)
{
    const double PoundsInKilogram = 2.2;
    return pounds / PoundsInKilogram;
}

double bmi(double weight, double height)
{
    return weight / (height * height);
}
