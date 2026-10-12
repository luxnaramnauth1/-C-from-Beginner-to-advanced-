# 01 · Basics (Beginner)

Your first C++ program: variables, types, output, and control flow.

## What you will learn

- Built-in types: `int`, `double`, `char`, `bool`, and `std::string`
- `const` for values that must not change
- `auto` for type deduction
- `if`/`else`, `for`, `while`, and `switch`
- Integer versus floating-point division

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

On Windows with MSVC, use a Developer Command Prompt and run `cl /std:c++17 /EHsc main.cpp`.

## Expected output

```
Ada is 36 years old
Price with tax: 23.988
Grade: A, learning: true
In ten years: 46
Adult
Countdown: 3 2 1 liftoff!
First power of two >= 100: 128
Excellent
7 / 2 = 3, 7.0 / 2 = 3.5
```

## Key takeaways

- C++ is statically typed. Each variable has one type that is fixed at compile time.
- `7 / 2` is `3` because both operands are integers. Use `7.0 / 2` to get `3.5`.
- `std::string` is a standard library type, so it needs `#include <string>`.

## Exercises

1. Ask the user for their age with `std::cin` and print whether they are an adult.
2. Print the numbers from 1 to 20 that are divisible by 3.
3. Change `TAX_RATE` to `const` and try assigning to it. Read the compiler error.

**Next:** `02-beginner-functions`
