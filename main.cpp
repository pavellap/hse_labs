#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * Function generates vector filled with random numbers with given size of array
 * @param size
 * @returns generated vector
 * */
vector<int> makeRandomVector(unsigned int size=40, int left_limit=-10000, int right_limit=10000) {
    vector<int> v(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(left_limit, right_limit);
    generate(v.begin(), v.end(), [&]{return distribution(gen);});
    return v;
}

int main() {

    auto generated_vector = makeRandomVector();

    for (auto i = generated_vector.begin(); i != generated_vector.end(); i++) {
        if (*i % 2 != 0 or *i <= 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}