//exercise_1
#include <iostream>

class Tree {
public:
    virtual void draw() const = 0;
};

class PineTree : public Tree {
public:
    void draw() const override {
        std::cout << "   /\\   " << std::endl;
        std::cout << "  /  \\  " << std::endl;
        std::cout << " /    \\ " << std::endl;
        std::cout << "/______\\" << std::endl;
    }
};

class OakTree : public Tree {
public:
    void draw() const override {
        std::cout << "   /\\   " << std::endl;
        std::cout << "  /  \\  " << std::endl;
        std::cout << " /    \\ " << std::endl;
        std::cout << "/______\\" << std::endl;
    }
};

class WillowTree : public Tree {
public:
    void draw() const override {
        std::cout << "   /\\   " << std::endl;
        std::cout << "  /  \\  " << std::endl;
        std::cout << " /    \\ " << std::endl;
        std::cout << "/______\\" << std::endl;
    }
};

int main() {
    Tree* trees[3];

    PineTree pine;
    OakTree oak;
    WillowTree willow;

    trees[0] = &pine;
    trees[1] = &oak;
    trees[2] = &willow;

    for (int i = 0; i < 3; ++i) {
        trees[i]->draw();
        std::cout << std::endl;
    }

    return 0;
}

//exercise_2
#include <iostream>
#include <string>

class IPAddress {
protected:
    std::string address;

public:
    IPAddress(const std::string& addr) : address(addr) {}
    IPAddress(const IPAddress& other) : address(other.address) {}

    virtual void print() const {
        std::cout << "IP Address: " << address << std::endl;
    }
};

class IPAddressChecked : public IPAddress {
private:
    bool isCorrect;

public:
    IPAddressChecked(const std::string& addr, bool correct) : IPAddress(addr), isCorrect(correct) {}
    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other), isCorrect(other.isCorrect) {}

    void print() const override {
        IPAddress::print();
        std::cout << "Correctness: " << (isCorrect ? "Correct" : "Not Correct") << std::endl;
    }
};

int main() {
    std::string ip1, ip2, ip3;
    bool correct2, correct3;

    std::cout << "Enter IP Address 1: ";
    std::cin >> ip1;
    std::cout << "Enter IP Address 2: ";
    std::cin >> ip2;
    std::cout << "Is IP Address 2 correct? (1 for true, 0 for false): ";
    std::cin >> correct2;
    std::cout << "Enter IP Address 3: ";
    std::cin >> ip3;
    std::cout << "Is IP Address 3 correct? (1 for true, 0 for false): ";
    std::cin >> correct3;

    IPAddress ipObj(ip1);
    IPAddressChecked ipCheckedObj1(ip2, correct2);
    IPAddressChecked ipCheckedObj2(ip3, correct3);

    std::cout << "Printing IP Address 1:" << std::endl;
    ipObj.print();
    std::cout << std::endl;

    std::cout << "Printing IP Address 2:" << std::endl;
    ipCheckedObj1.print();
    std::cout << std::endl;

    std::cout << "Printing IP Address 3:" << std::endl;
    ipCheckedObj2.print();
    std::cout << std::endl;

    return 0;
}
