// 03 | BEGINNER | Arrays, std::vector, and std::string
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
    // C-style array: fixed size, no bounds checking. Avoid it in new code.
    int fixed[3] = {10, 20, 30};
    std::cout << "fixed[1] = " << fixed[1] << '\n';

    // std::vector: a dynamic array that can grow
    std::vector<int> scores = {90, 75, 88};
    scores.push_back(95);
    std::cout << "size = " << scores.size() << '\n';

    // Range-based for loop
    int total = 0;
    for (int s : scores) {
        total += s;
    }
    std::cout << "average = "
              << static_cast<double>(total) / static_cast<double>(scores.size()) << '\n';

    // at() checks bounds and throws; [] does not check
    try {
        std::cout << scores.at(10);
    } catch (const std::out_of_range& e) {
        std::cout << "caught: " << e.what() << '\n';
    }

    // Sorting and summing
    std::sort(scores.begin(), scores.end());   // ascending order
    std::cout << "sorted:";
    for (int s : scores) std::cout << ' ' << s;
    std::cout << '\n';

    int sum = std::accumulate(scores.begin(), scores.end(), 0);
    std::cout << "sum = " << sum << '\n';

    // std::string
    std::string first = "Hello";
    std::string second = "World";
    std::string msg = first + ", " + second + "!";
    std::cout << msg << " (length " << msg.size() << ")\n";

    std::cout << "contains World? "
              << (msg.find("World") != std::string::npos ? "yes" : "no") << '\n';
    std::cout << "first five: " << msg.substr(0, 5) << '\n';

    // Count vowels, one character at a time
    int vowels = 0;
    for (char c : msg) {
        switch (c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                ++vowels;
                break;
            default:
                break;
        }
    }
    std::cout << "vowels = " << vowels << '\n';

    return 0;
}
