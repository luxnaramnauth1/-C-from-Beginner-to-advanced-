// 01 | BEGINNER | Variables, types, input/output, and control flow
#include <iostream>
#include <string>

int main() {
    // Built-in types
    int age = 36;
    double price = 19.99;
    char grade = 'A';
    bool isLearning = true;
    std::string name = "Ada";   // std::string comes from <string>

    // const: the value cannot change after it is set
    const double TAX_RATE = 0.20;

    std::cout << name << " is " << age << " years old\n";
    std::cout << "Price with tax: " << price * (1 + TAX_RATE) << '\n';
    std::cout << "Grade: " << grade << ", learning: " << std::boolalpha << isLearning << '\n';

    // auto: the compiler deduces the type (int here)
    auto inTenYears = age + 10;
    std::cout << "In ten years: " << inTenYears << '\n';

    // if / else
    if (age >= 18) {
        std::cout << "Adult\n";
    } else {
        std::cout << "Minor\n";
    }

    // for loop
    std::cout << "Countdown:";
    for (int i = 3; i > 0; --i) {
        std::cout << ' ' << i;
    }
    std::cout << " liftoff!\n";

    // while loop
    int n = 1;
    while (n < 100) {
        n *= 2;
    }
    std::cout << "First power of two >= 100: " << n << '\n';

    // switch
    switch (grade) {
        case 'A': std::cout << "Excellent\n"; break;
        case 'B': std::cout << "Good\n";      break;
        default:  std::cout << "Keep going\n"; break;
    }

    // Integer division truncates; use a double operand for decimals
    std::cout << "7 / 2 = " << 7 / 2 << ", 7.0 / 2 = " << 7.0 / 2 << '\n';

    // Reading input: uncomment to type a number when the program runs
    // int x;
    // std::cin >> x;

    return 0;
}
