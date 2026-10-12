// 08 | ADVANCED | Templates: function templates, class templates, fold expressions, if constexpr
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

// ---- Function template: one definition, many types -----------------------------------
template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

// ---- Non-type template parameter: the size is part of the type ---------------------------
template <typename T, std::size_t N>
constexpr std::size_t arraySize(const T (&)[N]) {
    return N;
}

// ---- Class template: a generic stack ---------------------------------------------------------
template <typename T>
class Stack {
public:
    void push(T value) {
        items_.push_back(std::move(value));
    }

    T pop() {
        if (items_.empty()) {
            throw std::out_of_range("pop from empty stack");
        }
        T top = std::move(items_.back());
        items_.pop_back();
        return top;
    }

    bool empty() const { return items_.empty(); }
    std::size_t size() const { return items_.size(); }

private:
    std::vector<T> items_;
};

// ---- Variadic template with a fold expression (C++17) -----------------------------------------
// Adds any number of arguments. With no arguments, the result is 0.
template <typename... Args>
auto sumAll(Args... args) {
    return (args + ... + 0);
}

// ---- if constexpr: choose code paths at compile time -------------------------------------------
template <typename T>
std::string describe(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        return "integer " + std::to_string(value);
    } else if constexpr (std::is_floating_point_v<T>) {
        return "floating-point " + std::to_string(value);
    } else {
        return "other type";
    }
}

// ---- Constraining templates with enable_if (pre-C++20 style) ------------------------------------
template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
T square(T value) {
    return value * value;
}

int main() {
    std::cout << "maxOf(3, 7) = " << maxOf(3, 7) << '\n';
    std::cout << "maxOf(2.5, 1.5) = " << maxOf(2.5, 1.5) << '\n';
    std::cout << "maxOf<std::string> = "
              << maxOf<std::string>("apple", "banana") << '\n';

    int nums[] = {10, 20, 30, 40};
    std::cout << "arraySize = " << arraySize(nums) << '\n';

    Stack<int> ints;
    ints.push(1);
    ints.push(2);
    std::cout << "popped " << ints.pop() << ", size now " << ints.size() << '\n';

    Stack<std::string> words;
    words.push("generic");
    words.push("stack");
    std::cout << "top word: " << words.pop() << '\n';

    try {
        Stack<double> empty;
        empty.pop();
    } catch (const std::out_of_range& e) {
        std::cout << "error: " << e.what() << '\n';
    }

    std::cout << "sumAll(1, 2, 3, 4) = " << sumAll(1, 2, 3, 4) << '\n';
    std::cout << "sumAll(1.5, 2.5) = " << sumAll(1.5, 2.5) << '\n';

    std::cout << describe(42) << '\n';
    std::cout << describe(3.14) << '\n';
    std::cout << describe(std::string("hi")) << '\n';

    std::cout << "square(7) = " << square(7) << '\n';
    // square("text");   // compile error: the constraint rejects non-arithmetic types

    return 0;
}
