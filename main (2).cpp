// 09 | ADVANCED | Smart pointers, move semantics, and rvalue references
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// A class that owns a raw array. It follows the "rule of five":
// copy constructor, move constructor, copy assignment, move assignment, destructor.
class Buffer {
public:
    explicit Buffer(std::size_t n) : size_(n), data_(new int[n]()) {
        std::cout << "  Buffer(" << n << ") constructed\n";
    }

    // Copy: deep copy, which can be expensive
    Buffer(const Buffer& other) : size_(other.size_), data_(new int[other.size_]) {
        std::copy(other.data_, other.data_ + size_, data_);
        std::cout << "  Buffer copied\n";
    }

    // Move: take the pointer and leave the source empty. This is cheap.
    Buffer(Buffer&& other) noexcept : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
        std::cout << "  Buffer moved\n";
    }

    Buffer& operator=(const Buffer&) = delete;
    Buffer& operator=(Buffer&&) = delete;

    ~Buffer() {
        delete[] data_;   // safe even if data_ is nullptr
    }

    std::size_t size() const { return size_; }

private:
    std::size_t size_;
    int* data_;
};

struct TreeNode {
    std::string name;
    std::weak_ptr<TreeNode> parent;                  // does not keep the parent alive
    std::vector<std::shared_ptr<TreeNode>> children; // parent owns children
};

// Factory function: returning unique_ptr transfers ownership to the caller
std::unique_ptr<Buffer> makeBuffer(std::size_t n) {
    return std::make_unique<Buffer>(n);
}

// Takes an rvalue reference: it can only be called with temporaries or std::move results
void consume(std::string&& text) {
    std::cout << "  consumed: " << text << '\n';
}

int main() {
    // ---- unique_ptr: exclusive ownership ---------------------------------------------------
    std::cout << "unique_ptr:\n";
    auto u1 = std::make_unique<std::string>("exclusive");
    auto u2 = std::move(u1);                  // ownership moves to u2
    std::cout << "  u1 is " << (u1 ? "set" : "null") << ", u2 holds \"" << *u2 << "\"\n";

    auto buf = makeBuffer(3);
    std::cout << "  buffer size: " << buf->size() << '\n';

    // ---- shared_ptr: shared ownership with a reference count -----------------------------------
    std::cout << "shared_ptr:\n";
    auto s1 = std::make_shared<int>(10);
    {
        auto s2 = s1;                          // another owner
        std::cout << "  use_count inside block: " << s1.use_count() << '\n';   // 2
    }
    std::cout << "  use_count after block: " << s1.use_count() << '\n';        // 1

    // ---- weak_ptr: observe without owning, which breaks reference cycles ---------------------------
    std::cout << "weak_ptr:\n";
    auto root = std::make_shared<TreeNode>();
    root->name = "root";
    auto child = std::make_shared<TreeNode>();
    child->name = "child";
    child->parent = root;                      // child does not keep root alive
    root->children.push_back(child);

    if (auto parent = child->parent.lock()) {  // lock() gives a shared_ptr or nullptr
        std::cout << "  child's parent: " << parent->name << '\n';
    }

    // ---- Move semantics ----------------------------------------------------------------------------
    std::cout << "move semantics:\n";
    Buffer a(4);
    Buffer b = std::move(a);                   // move constructor
    Buffer c(b);                               // copy constructor (b is an lvalue)
    std::cout << "  sizes: a=" << a.size() << " b=" << b.size() << " c=" << c.size() << '\n';

    std::vector<std::string> items;
    std::string longText(50, 'x');
    items.push_back(std::move(longText));      // moves the string into the vector
    std::cout << "  items stored: " << items.size() << ", first length: "
              << items[0].size() << '\n';

    std::cout << "rvalue reference:\n";
    consume(std::string("temporary"));         // a temporary binds to the rvalue reference
    std::string named = "named";
    consume(std::move(named));                 // std::move turns a named value into an rvalue

    std::cout << "done (all memory released automatically)\n";
    return 0;
}
