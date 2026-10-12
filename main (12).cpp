// 06 | INTERMEDIATE | Inheritance, virtual functions, polymorphism, and abstract classes
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

constexpr double kPi = 3.141592653589793;

// Abstract base class: it has at least one pure virtual function (= 0),
// so Shape cannot be instantiated directly.
class Shape {
public:
    virtual ~Shape() = default;               // virtual destructor: required for base classes
    virtual double area() const = 0;          // every shape must implement this
    virtual std::string name() const { return "shape"; }
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}

    double area() const override { return kPi * radius_ * radius_; }
    std::string name() const override { return "circle"; }

private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double area() const override { return width_ * height_; }
    std::string name() const override { return "rectangle"; }

protected:                  // accessible to derived classes
    double width_;
    double height_;
};

// final: no further subclasses allowed
class Square final : public Rectangle {
public:
    explicit Square(double side) : Rectangle(side, side) {}

    std::string name() const override { return "square"; }
};

// Works with any Shape, without knowing its concrete type
void printShape(const Shape& shape) {
    std::cout << shape.name() << " area: " << shape.area() << '\n';
}

int main() {
    // Smart pointers (lesson 09) manage each object's lifetime.
    // A vector of base-class pointers stores different shape types together.
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2.0));
    shapes.push_back(std::make_unique<Rectangle>(3.0, 4.0));
    shapes.push_back(std::make_unique<Square>(5.0));

    // Dynamic dispatch: each call runs the override for the object's real type
    double total = 0.0;
    for (const auto& shape : shapes) {
        printShape(*shape);
        total += shape->area();
    }
    std::cout << "total area: " << total << '\n';

    // Upcasting: a derived object is a base object
    Square sq(2.0);
    const Shape& asBase = sq;
    std::cout << "via base reference: " << asBase.name() << ", area " << asBase.area() << '\n';

    return 0;
}
