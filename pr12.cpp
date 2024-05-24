#exercise_1
#include <iostream>

double divide(double a, double b) {
    if (b == 0) {
        throw "Division by zero error";
    }
    return a / b;
}

int main() {
    try {
        double x, y;
        std::cout << "Enter two numbers: ";
        std::cin >> x >> y;

        double result = divide(x, y);
        std::cout << "Result: " << result << std::endl;

    } catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}

#exercise_2
#include <iostream>

int main() {
    int numerator, denominator;

    std::cout << "Enter the numerator: ";
    std::cin >> numerator;

    std::cout << "Enter the denominator: ";
    std::cin >> denominator;

    try {
        if (denominator == 0) {
            throw "Division by zero is not allowed!";
        }

        int result = numerator / denominator;
        std::cout << "Result of division: " << result << std::endl;
    }
    catch (const char* errorMessage) {
        std::cerr << "Error: " << errorMessage << std::endl;
    }
    catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
    }

    return 0;
}
#exercise_3
#include <iostream>
#include <stdexcept>

using namespace std;

float divide_numbers() {
    float dividend, divisor;
    cout << "Enter the dividend: ";
    cin >> dividend;
    cout << "Enter the divisor: ";
    cin >> divisor;
    
    if (divisor == 0) {
        throw invalid_argument("Division by zero is not allowed. Please enter a non-zero divisor.");
    }
    
    return dividend / divisor;
}

int main() {
    try {
        float result = divide_numbers();
        cout << "Result: " << result << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
