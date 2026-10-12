// 07 | INTERMEDIATE | STL containers, iterators, algorithms, and lambdas
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

struct Employee {
    std::string name;
    int age;
    double salary;
};

int main() {
    // ---- std::map: sorted keys --------------------------------------------------------
    std::map<std::string, int> wordCount;
    std::istringstream stream("the quick brown fox jumps over the lazy dog the end");
    std::string word;
    while (stream >> word) {
        ++wordCount[word];   // inserts with value 0 if the key is new
    }
    std::cout << "words used more than once:\n";
    for (const auto& [w, count] : wordCount) {   // structured binding (C++17)
        if (count > 1) {
            std::cout << "  " << w << ": " << count << '\n';
        }
    }

    // ---- std::set: unique, sorted values --------------------------------------------------
    std::set<int> unique = {5, 1, 3, 5, 1, 9};
    std::cout << "unique values:";
    for (int v : unique) std::cout << ' ' << v;   // 1 3 5 9
    std::cout << '\n';

    // ---- std::unordered_map: fast lookup, no ordering -------------------------------------------
    std::unordered_map<std::string, double> prices = {{"apple", 0.5}, {"bread", 2.25}};
    if (auto it = prices.find("bread"); it != prices.end()) {   // if with initializer
        std::cout << "bread costs " << it->second << '\n';
    }

    // ---- std::deque: fast insertion at both ends ----------------------------------------------------
    std::deque<int> dq;
    dq.push_back(2);
    dq.push_front(1);
    dq.push_back(3);
    std::cout << "deque front=" << dq.front() << " back=" << dq.back() << '\n';

    // ---- Algorithms with lambdas -----------------------------------------------------------------------
    std::vector<Employee> staff = {
        {"Ada", 36, 85000.0},
        {"Grace", 45, 98000.0},
        {"Linus", 28, 72000.0},
    };

    // Sort by salary, highest first
    std::sort(staff.begin(), staff.end(),
              [](const Employee& a, const Employee& b) { return a.salary > b.salary; });

    std::cout << "by salary:";
    for (const auto& e : staff) std::cout << ' ' << e.name;
    std::cout << '\n';

    // find_if: first match
    auto over40 = std::find_if(staff.begin(), staff.end(),
                               [](const Employee& e) { return e.age > 40; });
    if (over40 != staff.end()) {
        std::cout << "first over 40: " << over40->name << '\n';
    }

    // count_if: how many match
    auto highEarners = std::count_if(staff.begin(), staff.end(),
                                     [](const Employee& e) { return e.salary >= 80000.0; });
    std::cout << "earning 80k+: " << highEarners << '\n';

    // transform: build a new vector from an existing one
    std::vector<std::string> names;
    names.reserve(staff.size());
    std::transform(staff.begin(), staff.end(), std::back_inserter(names),
                   [](const Employee& e) { return e.name; });
    std::cout << "names:";
    for (const auto& n : names) std::cout << ' ' << n;
    std::cout << '\n';

    // Erase-remove idiom: delete values that match a condition
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(),
                                 [](int n) { return n % 2 == 0; }),
                  numbers.end());
    std::cout << "odd numbers:";
    for (int n : numbers) std::cout << ' ' << n;
    std::cout << '\n';

    // Lambda capture: [&] captures by reference, [=] by value
    int threshold = 4;
    auto aboveThreshold = [threshold](int n) { return n > threshold; };
    std::cout << "numbers above " << threshold << ": "
              << std::count_if(numbers.begin(), numbers.end(), aboveThreshold) << '\n';

    return 0;
}
