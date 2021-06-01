#include <vector>
#include <iostream>
#include <array>
#include <map>

namespace utils {

   /* bool compare_floats(float first, float second) {
        return std::abs(first - second) <= 1e-6;
    }*/

    template<typename T>
    void print_array(std::vector<T> array) {
        for (auto iterator = array.begin(); iterator != array.end(); iterator++) {
            std::cout << *iterator << " ";
        }
        std::cout << "" << std::endl;
    }
    template<typename T>
    void print_array(std::array<T, 4> array) {
        for (auto iterator = array.begin(); iterator != array.end(); iterator++) {
            std::cout << *iterator << " ";
        }
        std::cout << "" << std::endl;
    }


    template<typename K, typename T>
    void print_array(std::map<T, K> map) {
        for (auto it = map.cbegin(); it != map.cend(); ++it)
            std::cout << it->first << ": " << it->second << std::endl;
    }
}

