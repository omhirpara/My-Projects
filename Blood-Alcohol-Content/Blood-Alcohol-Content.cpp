#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double stdDrinks,
        weight,
        hours;

    int gender;
    string genderType;

    double percentageBAC;
    double genderConstant = 0;

    //variable for choosing if user wants to make another BAC estimate
    int option;

    cout << "The program will function until you enter a sentinal value of -1." << endl;
    cout << "If you want to run the program, enter any number other than -1." << endl;
    cin >> option;

    //loop for entire program
    while (option != -1)
    {

        //user input for number of standard drinks
        cout << "\nHow many standard drinks did you have?\n" << endl;
        cout << "A standard drink is one 12-ounce beer, one" << endl;
        cout << "5-ounce glass of wine, or one 1.5-ounce shot of distilled liquor.\n" << endl;
        cout << "Enter the number of standard drinks:";
        cin >> stdDrinks;

        //validating user input for number of standard drinks
        while (stdDrinks < 1)
        {
            cout << "\nPlease enter a value greater than or equal to 1:";
            cin >> stdDrinks;
        }

        //user input for weight in pounds
        cout << "\nWhat is your weight in pounds?" << endl;
        cout << "Weight:";
        cin >> weight;

        //validating user input for weight in pounds
        while (weight <= 0)
        {
            cout << "\nPlease enter a value of weight in pounds greater than 0:";
            cin >> weight;
        }

        // user input for gender
        cout << "\nAre you a male or female?\n";
        cout << "Please input a 0 for male and 1 for female:";
        cin >> gender;

        //validating user input for gender
        while (gender != 0 && gender != 1)
        {
            cout << "\nPlease input a 0 for male and 1 for female:";
            cin >> gender;
        }

        //condition for male or female based on input
        if (gender == 0)
        {
            genderConstant = 0.68;
            genderType = "Male";
        }
        else
        {
            genderConstant = 0.55;
            genderType = "Female";
        }

        //user input for number for hours since the first drink
        cout << "\nHow many hours have passed since your first drink?" << endl;
        cout << "Enter the number hours since first drink:";
        cin >> hours;

        //validating user input for number of hours since the first drink
        while (hours <= 0)
        {
            cout << "\nPlease enter a number of hours greater than 0:";
            cin >> hours;
        }

        cout << "\nThe number of standard drinks is " << stdDrinks << endl;
        cout << "The weight in pounds is " << weight << endl;
        cout << "Your gender is " << genderType << endl;
        cout << "The number of hours since your first drink is " << hours << endl;

        //calculating percentage of BAC using Widmark formula
        percentageBAC = -0.015 * (double)hours + ((2.84 * (double)stdDrinks) / ((double)weight * genderConstant));
        cout << "\nYour BAC value is " << fixed << setprecision(3) << percentageBAC << "%" << endl;

        //condition for when BAC is at least 0.08% prints warning
        if (percentageBAC >= 0.08)
        {
            cout << "Over the legal limit for driving" << endl;
        }

        //condition for when BAC is less than 0.03% and prints effects
        if (percentageBAC < 0.03)
        {
            cout << "Possible Effects: Normal behavior, no impairment" << endl;
        }
        //condition for when BAC is greater than or equal to 0.03% and less than 0.06% and prints effects
        else if (percentageBAC >= 0.03 && percentageBAC < 0.06)
        {
            cout << "Possible Effects: Mild Euphoria and impairment" << endl;
        }
        //condition for when BAC is greater than or equal to 0.06% and less than 0.10% and prints effects
        else if (percentageBAC >= 0.06 && percentageBAC < 0.10)
        {
            cout << "Possible Effects: Euphoric, incrased impairment" << endl;
        }
        //condition for when BAC is greater than or equal to 0.10% and less than 0.20% and prints effects
        else if (percentageBAC >= 0.10 && percentageBAC < 0.20)
        {
            cout << "Possible Effects: Drunk, loss of motor control" << endl;
        }
        //condition for when BAC is greater than or equal to 0.20% and less than 0.30% and prints effects
        else if (percentageBAC >= 0.20 && percentageBAC < 0.30)
        {
            cout << "Possible Effects: Confused, possible blackout" << endl;
        }
        //condition for when BAC is greater than or equal to 0.30% and less than 0.40% and prints effects
        else if (percentageBAC >= 0.30 && percentageBAC < 0.40)
        {
            cout << "Possible Effects: Possibly unconscious" << endl;
        }
        //condition for when BAC is greater than or equal to 0.40% and prints effects
        else
        {
            cout << "Possible Effects: Unconscious, risk of death" << endl;
        }

        //checks if user wants to run the program again to estimate another BAC
        cout << "\nDo you want to run the program again?" << endl;
        cout << "If yes, enter any number other than -1. If no, enter -1.\n";
        cin >> option;
    }

    return 0;
}
