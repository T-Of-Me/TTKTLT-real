#include <iostream>
#include <vector>
#include <set>
#include <string>

int main() {
    std::vector<std::string> strings = {"apple", "banana", "apple", "orange", "banana", "grape"};
    std::set<std::string> uniqueStrings;

    for (const auto& str : strings) {
        uniqueStrings.insert(str);
    }

    std::cout << "Các chu?i khác nhau là: ";
    for (const auto& str : uniqueStrings) {
        std::cout << str << " ";
    }

    return 0;
}
