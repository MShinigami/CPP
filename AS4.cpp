#include <iostream>
using namespace std;

class Calculator
{
public:
    float a, b;

    void get_data()
    {
        cout << "Enter the First Value: ";
        cin >> a;
        cout << "Enter the Second Value: ";
        cin >> b;
    }

    float addition()
    {
        return (a + b);
    }

    float subtraction()
    {
        return (a - b);
    }

    float multiplication()
    {
        return (a * b);
    }

    float division()
    {
        if (b != 0) {
            return (a / b);
        } else {
            cout << "Error: Division by zero!" << endl;
            return 0.0;
        }
    }
};

int main() 
{
    Calculator calc;
    int choice;

    do 
    {
        cout << "Select an operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                calc.get_data();
                cout << "Sum: " << calc.addition() << endl;
                break;
            case 2:
                calc.get_data();
                cout << "Difference: " << calc.subtraction() << endl;
                break;
            case 3:
                calc.get_data();
                cout << "Product: " << calc.multiplication() << endl;
                break;
            case 4:
                calc.get_data();
                cout << "Quotient: " << calc.division() << endl;
                break;
            case 5:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option (1-5)." << endl;
        }
    } 
    while (choice != 5);

    return 0;
}