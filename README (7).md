# 08 · Templates (Advanced)

Writing generic code that the compiler specialises for each type you use.

## What you will learn

- Function templates and template argument deduction
- Class templates such as a generic `Stack<T>`
- Non-type template parameters (`std::size_t N`)
- Variadic templates and fold expressions (C++17)
- `if constexpr` for compile-time branching
- Constraining templates with `std::enable_if_t`

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

## Expected output

```
maxOf(3, 7) = 7
maxOf(2.5, 1.5) = 2.5
maxOf<std::string> = banana
arraySize = 4
popped 2, size now 1
top word: stack
error: pop from empty stack
sumAll(1, 2, 3, 4) = 10
sumAll(1.5, 2.5) = 4
integer 42
floating-point 3.140000
other type
square(7) = 49
```

`describe` uses `std::to_string`, which always shows six decimal places (`3.140000`). Plain `std::cout` output, such as `sumAll(1.5, 2.5)`, uses the shorter default format.

## Key takeaways

- Templates are checked and generated at compile time, so there is no runtime cost for generality.
- Errors in templates can be long and hard to read. Keep the constraints clear and small.
- `if constexpr` removes branches the compiler does not need, which is often cleaner than overloads.
- C++20 concepts (`template <std::integral T>`) express the same constraints more clearly. Use them if your compiler supports C++20.

## Exercises

1. Add a `peek()` method to `Stack<T>` that returns a reference to the top item without removing it.
2. Write a template `clamp(value, low, high)` and test it with `int` and `double`.
3. Compile with `-std=c++20` and rewrite `square` using a concept.

**Previous:** `07-intermediate-stl-containers` · **Next:** `09-advanced-smart-pointers-move`
