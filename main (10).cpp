// 05 | INTERMEDIATE | Classes, constructors, encapsulation, operator overloading, and RAII
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

class BankAccount {
public:
    // Constructor with a member initializer list.
    // std::move transfers the string instead of copying it.
    BankAccount(std::string owner, double initial = 0.0)
        : owner_(std::move(owner)), balance_(initial) {
        if (initial < 0) {
            throw std::invalid_argument("initial balance cannot be negative");
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("deposit must be positive");
        }
        balance_ += amount;
    }

    void withdraw(double amount) {
        if (amount > balance_) {
            throw std::runtime_error("insufficient funds");
        }
        balance_ -= amount;
    }

    // const member function: promises not to modify the object
    double balance() const { return balance_; }
    const std::string& owner() const { return owner_; }

private:
    std::string owner_;   // private data: encapsulation
    double balance_;
};

// A small value type with operator overloading
class Vec2 {
public:
    constexpr Vec2(double x = 0.0, double y = 0.0) : x_(x), y_(y) {}

    Vec2 operator+(const Vec2& other) const { return {x_ + other.x_, y_ + other.y_}; }
    Vec2 operator*(double k) const { return {x_ * k, y_ * k}; }
    bool operator==(const Vec2& other) const { return x_ == other.x_ && y_ == other.y_; }

    // Friend: can access private members, and lets std::cout print a Vec2
    friend std::ostream& operator<<(std::ostream& os, const Vec2& v) {
        return os << '(' << v.x_ << ", " << v.y_ << ')';
    }

private:
    double x_;
    double y_;
};

// RAII (Resource Acquisition Is Initialization):
// the constructor acquires a resource and the destructor releases it.
// Destructors run automatically when the object goes out of scope.
class ScopedLog {
public:
    explicit ScopedLog(std::string name) : name_(std::move(name)) {
        std::cout << "[open]  " << name_ << '\n';   // stands in for opening a file
    }
    ~ScopedLog() {
        std::cout << "[close] " << name_ << '\n';   // always runs, even on exceptions
    }

    // Copying would make two objects responsible for one resource, so forbid it
    ScopedLog(const ScopedLog&) = delete;
    ScopedLog& operator=(const ScopedLog&) = delete;

    void write(const std::string& message) const {
        std::cout << "[" << name_ << "] " << message << '\n';
    }

private:
    std::string name_;
};

int main() {
    BankAccount account("Ada", 100.0);
    account.deposit(50.0);
    std::cout << account.owner() << " balance: " << account.balance() << '\n';   // 150

    try {
        account.withdraw(500.0);
    } catch (const std::runtime_error& e) {
        std::cout << "error: " << e.what() << '\n';
    }

    try {
        BankAccount bad("Bob", -5.0);
    } catch (const std::invalid_argument& e) {
        std::cout << "error: " << e.what() << '\n';
    }

    Vec2 a(1.0, 2.0);
    Vec2 b(3.0, 4.0);
    std::cout << "a + b = " << a + b << '\n';          // (4, 6)
    std::cout << "a * 2 = " << a * 2.0 << '\n';        // (2, 4)
    std::cout << "a == b? " << std::boolalpha << (a == b) << '\n';

    // RAII in action: the log closes when the block ends
    {
        ScopedLog log("report.txt");
        log.write("first line");
        log.write("second line");
    }   // destructor runs here

    std::cout << "done\n";
    return 0;
}
