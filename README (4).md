# 09 · Smart Pointers and Move Semantics (Advanced)

Managing ownership without manual `delete`, and avoiding unnecessary copies.

## What you will learn

- `std::unique_ptr` for exclusive ownership, and `std::make_unique`
- `std::shared_ptr` for shared ownership and reference counts
- `std::weak_ptr` for non-owning references and breaking cycles
- The rule of five for classes that manage resources
- Move constructors and move assignment
- Rvalue references (`&&`) and `std::move`

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

Check for leaks with the address sanitizer:

```bash
g++ -std=c++17 -g -fsanitize=address,undefined main.cpp -o main_asan
./main_asan
```

It should finish without errors.

## Expected output

```
unique_ptr:
  u1 is null, u2 holds "exclusive"
  Buffer(3) constructed
  buffer size: 3
shared_ptr:
  use_count inside block: 2
  use_count after block: 1
weak_ptr:
  child's parent: root
move semantics:
  Buffer(4) constructed
  Buffer moved
  Buffer copied
  sizes: a=0 b=4 c=4
  items stored: 1, first length: 50
rvalue reference:
  consumed: temporary
  consumed: named
done (all memory released automatically)
```

## Key takeaways

- Prefer `std::unique_ptr` by default. Use `std::shared_ptr` only when several owners genuinely need the object.
- Use `std::make_unique` and `std::make_shared` instead of `new`, so memory is never leaked if an exception occurs partway through.
- Moving transfers a resource and leaves the source in a valid but unspecified state. Do not use a moved-from object except to assign to it or destroy it.
- A `weak_ptr` lets a child refer to its parent without keeping it alive. Without it, two `shared_ptr`s pointing at each other would never be freed.
- Mark move operations `noexcept`. Standard containers use them more aggressively when they cannot throw.

## Exercises

1. Write a `Document` class that owns a `std::vector<std::string>` and provides a move constructor. Measure the difference with a large vector.
2. Create a `shared_ptr` cycle on purpose, then fix it with `weak_ptr`. Track the lifetime with a destructor that prints a message.
3. Write a factory function that returns `std::shared_ptr<const Config>` and explain why `const` is useful.

**Previous:** `08-advanced-templates` · **Next:** `10-advanced-concurrency`
