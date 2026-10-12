# C++ Lessons: Beginner to Advanced

Ten self-contained C++ lessons, each in its own folder with a `main.cpp` program and a `README.md`. Work through them in order: each lesson builds on the one before.

## Learning path

| # | Folder | Level | Topics |
|---|--------|-------|--------|
| 01 | `01-beginner-basics` | Beginner | Types, `const`, `auto`, `if`, loops, `switch`, integer division |
| 02 | `02-beginner-functions` | Beginner | Functions, overloading, default arguments, references, lambdas |
| 03 | `03-beginner-arrays-strings` | Beginner | C arrays, `std::vector`, `std::string`, `<algorithm>` basics |
| 04 | `04-intermediate-pointers-references` | Intermediate | Pointers, references, `nullptr`, `new`/`delete`, dangling pointers |
| 05 | `05-intermediate-classes-raii` | Intermediate | Classes, constructors, encapsulation, operator overloading, RAII |
| 06 | `06-intermediate-inheritance-polymorphism` | Intermediate | Inheritance, `virtual`, `override`, abstract classes |
| 07 | `07-intermediate-stl-containers` | Intermediate | `map`, `set`, `unordered_map`, `deque`, algorithms, lambdas |
| 08 | `08-advanced-templates` | Advanced | Function and class templates, variadic templates, `if constexpr` |
| 09 | `09-advanced-smart-pointers-move` | Advanced | `unique_ptr`, `shared_ptr`, `weak_ptr`, move semantics, rvalue references |
| 10 | `10-advanced-concurrency` | Advanced | Threads, mutexes, atomics, `std::async`, promises and futures |

## Requirements

- A C++17 compiler: **g++ 9+**, **clang++ 10+**, or **MSVC 2019+**
- Optional: `valgrind` (Linux) and the sanitizers that come with g++ or clang

## Build and run any lesson

```bash
cd 01-beginner-basics
g++ -std=c++17 -Wall -Wextra -pedantic -pthread main.cpp -o main
./main
```

`-pthread` is harmless in lessons that do not use threads, so it is included everywhere.

## Build all lessons at once

```bash
for dir in */; do
  echo "== $dir"
  (cd "$dir" && g++ -std=c++17 -Wall -Wextra -pedantic -pthread main.cpp -o main && ./main)
done
```

## Suggested study approach

1. Read the lesson's `README.md`.
2. Build and run `main.cpp`, and compare the output with the expected output in the README.
3. Change one thing at a time and predict the result before you run it.
4. Do the exercises at the end of each README.

## License

Free to use and adapt for learning.
