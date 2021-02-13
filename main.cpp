#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

/**
 * Function generates vector filled with random numbers with given size of array
 * @param size - size of generated array
 * @param left_limit - lowest possible number in generated array
 * @param right_limit - height possible number in generated array
 * @param generate_even_numbers_only - if true, generates only even numbers
 * @returns generated vector
 * */
vector<int> makeRandomVector(unsigned int size = 40, int left_limit = -10000, int right_limit = 10000,
                             bool generate_even_numbers_only = false) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(left_limit, right_limit);
    if (generate_even_numbers_only) {
        vector<int> v(0);
        for (int i = 0; i < size;) {
            auto item = distribution(gen);
            if (item % 2 == 0) {
                v.push_back(item);
                i++;
            }
        }
        return v;
    }

    vector<int> v(size);
    generate(v.begin(), v.end(), [&] { return distribution(gen); });
    return v;
}


std::string check_first_condition(vector<int> array) {
    for (auto iterator = array.begin(); iterator != array.end(); iterator++) {
        if (*iterator < 0 or *iterator % 2 == 1) {
            cout << "NO" << endl;
            return "NO";
        }
    }
    cout << "YES" << endl;
    return "YES";
}

template<typename T>
void print_array(vector<T> array) {
    for (auto iterator = array.begin(); iterator != array.end(); iterator++) {
        cout << *iterator << " ";
    }
    cout << "" << endl;
}


int main() {
    /**1st part of the task*/
    auto generated_vector = makeRandomVector();
    auto evens = makeRandomVector(40, 0, 10000, true);

    /**uncomment these lines to print arrays*/
    //print_array(generated_vector);
    //print_array(evens);

    std::string result_first = check_first_condition(generated_vector);
    std::string result_second = check_first_condition(evens);

    // make test for generated array
    assert(result_first == "NO");
    assert(result_second == "YES");


    /**2st part of the task*/
    return 0;
}