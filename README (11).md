# 06 · Inheritance and Polymorphism (Intermediate)

Sharing behaviour through base classes and calling the correct function at runtime.

## What you will learn

- Public inheritance with `class Derived : public Base`
- `virtual` functions and dynamic dispatch
- Pure virtual functions and abstract classes
- Virtual destructors, and why base classes need them
- `override` and `final` to catch mistakes
- Using a base-class reference or pointer to work with many types

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

## Expected output

```
circle area: 12.5664
rectangle area: 12
square area: 25
total area: 49.5664
via base reference: square, area 4
```

The `area` lines use the default C++ floating-point output format, so the digits shown may differ slightly.

## Key takeaways

- `virtual` lets the program choose the override based on the object's actual type, not the pointer's declared type.
- Always give a base class a virtual destructor. Without it, deleting a derived object through a base pointer is undefined behaviour.
- `override` makes the compiler check that you really are overriding a base function.
- Prefer composition over inheritance when classes share data but not a clear "is-a" relationship.

## Exercises

1. Add a `Triangle` class with `base` and `height`, and include it in the vector.
2. Add a virtual function `perimeter()` to `Shape`, and implement it for each class.
3. Try removing the virtual destructor from `Shape`, and enable `-fsanitize=address` to observe the problem.

**Previous:** `05-intermediate-classes-raii` · **Next:** `07-intermediate-stl-containers`
