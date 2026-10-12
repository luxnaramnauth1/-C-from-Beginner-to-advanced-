# 07 · STL Containers and Algorithms (Intermediate)

Using the Standard Template Library to store data and transform it with lambdas.

## What you will learn

- Choosing a container: `vector`, `deque`, `map`, `set`, `unordered_map`
- Iterators and range-based loops
- Structured bindings (`auto& [key, value]`)
- `if` with an initializer
- Algorithms: `sort`, `find_if`, `count_if`, `transform`, `remove_if`
- The erase-remove idiom
- Lambda expressions and capture lists

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

## Expected output

```
words used more than once:
  the: 3
unique values: 1 3 5 9
bread costs 2.25
deque front=1 back=3
by salary: Grace Ada Linus
first over 40: Grace
earning 80k+: 2
names: Grace Ada Linus
odd numbers: 1 3 5 7
numbers above 4: 2
```

## Key takeaways

- Choose containers by behaviour. `vector` is the default. `map` keeps keys sorted. `unordered_map` gives fast lookups when order does not matter.
- Algorithms work on iterator ranges, so they work across containers.
- Lambdas make small, one-off rules readable. Use `[&]` or `[x]` to control what they capture.
- Since C++20 you can write `std::erase_if(numbers, pred)`. The erase-remove idiom shown here is the C++17 way.

## Exercises

1. Group the `Employee` list by age range using a `std::map<std::string, std::vector<Employee>>`.
2. Use `std::max_element` with a lambda to find the highest-paid employee.
3. Count the frequency of each character in a sentence, and print the top three.

**Previous:** `06-intermediate-inheritance-polymorphism` · **Next:** `08-advanced-templates`
