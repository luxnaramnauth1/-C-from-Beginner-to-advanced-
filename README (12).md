# 03 · Arrays, Vectors, and Strings (Beginner)

Storing collections of values and working with text.

## What you will learn

- C-style arrays, and why `std::vector` is usually the better choice
- `push_back`, `size`, `at`, and range-based `for` loops
- Sorting and summing with `<algorithm>` and `<numeric>`
- `std::string` operations: concatenation, `find`, `substr`, and `size`
- The difference between `[]` (no bounds check) and `at()` (bounds checked)

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

## Expected output

```
fixed[1] = 20
size = 4
average = 87
caught: vector::_M_range_check: __n (which is 10) >= this->size() (which is 4)
sorted: 75 88 90 95
sum = 348
Hello, World! (length 13)
contains World? yes
first five: Hello
vowels = 3
```

The exact text of the `caught:` message depends on your standard library.

## Key takeaways

- Use `std::vector` for lists whose size changes. Use `at()` while learning so mistakes throw instead of silently corrupting memory.
- `std::string` manages its own memory, so you do not need to free it.
- Cast to `double` before dividing two integers if you want a decimal result.

## Exercises

1. Find the largest value in a `std::vector<int>` using a loop, then with `std::max_element`.
2. Reverse a string using `std::reverse`.
3. Count how many words are in a sentence by splitting on spaces.

**Previous:** `02-beginner-functions` · **Next:** `04-intermediate-pointers-references`
