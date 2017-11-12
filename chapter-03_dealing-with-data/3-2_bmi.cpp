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

double feetAndInchesToMeters(int, int);
double poundsToKilograms(int);
double bmi(double, double);

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter your height in feet and inches:\nFeet: ";
    int feet;
    cin >> feet;

    cout << "Inches: ";
    int inches;
    cin >> inches;

    cout << "Now, enter your weight in pounds: ";
    int pounds;
    cin >> pounds;

    double heightMeters = feetAndInchesToMeters(feet, inches);
    double weightKilograms = poundsToKilograms(pounds);
    cout << "With a height of " << heightMeters << " m and a weight of " << weightKilograms
         << " kg your BMI is " << bmi(weightKilograms, heightMeters) << ".\n";

    return 0;
}

double feetAndInchesToMeters(int feet, int inches)
{
    const int InchesInFoot = 12;
    const double InchToMeter = 0.0254;

    return (feet * InchesInFoot + inches) * InchToMeter;
}

double poundsToKilograms(int pounds)
{
    const double PoundsInKilogram = 2.2;
    return pounds / PoundsInKilogram;
}

double bmi(double weight, double height)
{
    return weight / (height * height);
}
