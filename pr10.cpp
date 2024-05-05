//exercise_1
#include <iostream>
#include <unordered_map>

class GymMember {
private:
    std::string name;
    int monthsValid;
public:
    GymMember(std::string n) : name(n), monthsValid(0) {}

    int getMonthsValid() const {
        return monthsValid;
    }

    void extendSubscription(int n) {
        monthsValid += n;
    }

    void cancelSubscription() {
        monthsValid = 0;
    }
};

class Gym {
private:
    std::unordered_map<int, GymMember*> members;
    const int MAX_MEMBERS = 10;

//exercise_2
#include <iostream>
#include <sstream>
#include <cmath>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    std::string toString() const {
        int wholePart = numerator / denominator;
        int remainder = abs(numerator) % denominator;
        std::stringstream ss;
        if (wholePart != 0) {
            ss << wholePart << " ";
        }
        if (numerator < 0 && remainder != 0) {
            ss << "-";
        }
        if (remainder != 0) {
            int gcd = findGCD(abs(remainder), denominator);
            ss << abs(remainder) / gcd << "/" << denominator / gcd;
        }
        return ss.str();
    }

    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

private:
    int findGCD(int a, int b) const {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }
};

int main() {
    int numerator, denominator;
    char slash;
    
    std::cout << "Enter fraction in the form [numerator] / [denominator]: ";
    std::cin >> numerator >> slash >> denominator;
    
    Fraction fraction(numerator, denominator);
    
    std::cout << "Textual representation: " << fraction.toString() << std::endl;
    std::cout << "Floating-point representation: " << fraction.toDouble() << std::endl;
    
    return 0;
}
