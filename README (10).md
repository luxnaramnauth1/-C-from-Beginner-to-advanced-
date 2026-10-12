# 04 · Pointers, References, and Dynamic Memory (Intermediate)

Understanding memory addresses, the difference between pointers and references, and manual memory management.

## What you will learn

- Taking addresses with `&` and reading through pointers with `*`
- Pointer parameters versus reference parameters
- `nullptr` and why checking for it matters
- Pointer arithmetic on arrays
- Heap allocation with `new` and `delete`, and `new[]` with `delete[]`
- Dangling pointers, and how to avoid them

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

Optional memory check on Linux (install `valgrind` first):

```bash
valgrind --leak-check=full ./main
```

Valgrind should report no leaks.

## Expected output

```
x via pointer: 1
x now: 42
after pointer swap: x=2 y=42
after reference swap: x=42 y=2
empty is null
third via pointer arithmetic: 30
squares: 0 1 4 9 16
single = 7
limit via read-only pointer: 100
```

## Key takeaways

- A reference is an alias. It must be bound when created and cannot be null.
- A pointer holds an address. It can be null, reassigned, or dangling.
- Every `new` needs exactly one `delete`. Forgetting it causes a memory leak. Using memory after `delete` is undefined behaviour.
- Modern C++ avoids manual `new`/`delete`. Lesson 09 shows smart pointers, which free memory automatically.

## Exercises

1. Write a function that returns a pointer to the larger of two `int` values, and check for `nullptr` before using it.
2. Allocate an array of 1000 doubles with `new[]`, fill it, print the sum, then free it.
3. Use valgrind to find a leak: remove one `delete` and observe the report.

**Previous:** `03-beginner-arrays-strings` · **Next:** `05-intermediate-classes-raii`
