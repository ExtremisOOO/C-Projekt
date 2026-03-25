#pragma once
#include <string>

// -----------------------------------------------------------------------------
// Item
class Item {
    std::string name;
public:
    Item(const std::string& n) : name(n) {}
    virtual ~Item() = default;
    std::string getName() const { return name; }
};
