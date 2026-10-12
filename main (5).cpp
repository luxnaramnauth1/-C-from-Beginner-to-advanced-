// 02 | BEGINNER | Functions, overloading, default arguments, references, and lambdas
#include <iostream>
#include <string>

int add(int a, int b) { return a + b; }

// Overloading: same name, different parameter types
double add(double a, double b) { return a + b; }

// Default argument: the caller may omit it
// const std::string&: read-only reference, no copy is made
std::string greet(const std::string& name, const std::string& greeting = "Hello") {
    return greeting + ", " + name + "!";
}

// Pass by reference: changes the caller's variable
void increment(int& value) { ++value; }

// Pass by value: changes only a local copy
void tryIncrement(int value) { ++value; }

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(int a, int b) {
    return a < b ? MinMax{a, b} : MinMax{b, a};
}

// Recursion
unsigned long long factorial(unsigned int n) {
    return n <= 1 ? 1ULL : n * factorial(n - 1);
}

int main() {
    std::cout << add(2, 3) << '\n';          // int version: 5
    std::cout << add(2.5, 1.25) << '\n';     // double version: 3.75

    std::cout << greet("Ada") << '\n';           // uses the default greeting
    std::cout << greet("Grace", "Hi") << '\n';   // overrides the default

    int x = 10;
    tryIncrement(x);
    std::cout << "after tryIncrement: " << x << '\n';   // still 10
    increment(x);
    std::cout << "after increment: " << x << '\n';      // now 11

    auto mm = findMinMax(9, 4);
    std::cout << "min=" << mm.min << " max=" << mm.max << '\n';

    std::cout << "5! = " << factorial(5) << '\n';

    // Lambda: an unnamed function defined inline (C++11)
    auto square = [](int v) { return v * v; };
    std::cout << "square(7) = " << square(7) << '\n';

    return 0;
}
