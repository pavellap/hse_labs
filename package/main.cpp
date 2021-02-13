#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <cmath>
#include "utils.cpp"

using namespace std;



int second_part_first_task(vector<float> &array) {
    int counter = 0;
    for (auto iterator = array.begin(); iterator != array.end(); iterator++) {
        if (utils::compare_floats(fmod(*iterator, 5), 0)) {
            break;
        }
        counter++;
    }

    if (counter == array.size())
        cout << "There are no elements matching condition";
    else
        cout << "Found element multiple of 5" << endl << "Elements before this element: " << counter << endl;
    return counter;
}

void second_part_second_task(vector<float> &array, float k) {
    transform(array.begin(), array.end(), array.begin(), [k](float &c) {
        return utils::compare_floats(c, k) ? c * 2 : c;
    });
}

void second_part_third_task(vector<float> &array) {
    reverse(array.begin(), array.begin() + 5);
}

/**
 * Function generates vector filled with random numbers with given size of array
 * @param size - size of generated array
 * @param left_limit - lowest possible number in generated array
 * @param right_limit - height possible number in generated array
 * @param generate_even_numbers_only - if true, generates only even numbers
 * @returns generated vector
 * */
vector<int> makeRandomVector(unsigned int size = 40, int left_limit = -10000,
                             int right_limit = 10000,
                             bool generate_even_numbers_only = false) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> integer_distribution(left_limit, right_limit);
    if (generate_even_numbers_only) {
        vector<int> v(0);
        for (int i = 0; i < size;) {
            auto item = integer_distribution(gen);
            if (item % 2 == 0) {
                v.push_back(item);
                i++;
            }
        }
        return v;
    }

    vector<int> v(size);
    generate(v.begin(), v.end(), [&] { return integer_distribution(gen); });
    return v;
}

/**
 * Function generates vector filled with random real numbers with given size of array
 * @param size - size of generated array
 * @param left_limit - lowest possible number in generated array
 * @param right_limit - height possible number in generated array
 * @returns generated vector
 * */
vector<float> generate_real_array(unsigned int size = 40, int left_limit = -10000,
                                  int right_limit = 10000) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> real_distribution(left_limit, right_limit);
    vector<float> v(size);
    generate(v.begin(), v.end(), [&] { return real_distribution(gen); });
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


    /**
     * 2st part of the task
     * Дан массив из N вещественных чисел. Найти количество элементов, расположенных до первого элемента,
        кратного 5. Удвоить элементы массива, равные k. Если размер массива больше 4, то переставить первые 5
        элементов в обратном порядке. Перенести все нулевые элементы в конец массива, не меняя порядок
        следования остальных элементов. Отсортировать по возрастанию часть массива до первого максимального
        элемента
     *
     * */
    cout << "Please input length of array: ";
    unsigned int size;
    cin >> size;

    vector<float> real_array = generate_real_array(size);
    cout << "Generated array: " << endl;
    print_array(real_array);

    vector<float> sample({4.3, 5.0, 1.3, 10, 3, 4, 5, 3.1});
    second_part_first_task(sample);

    cout << "Please, input number K: " << endl;
    float k;
    cin >> k;
    second_part_second_task(sample, k);
    print_array(sample);
    second_part_third_task(sample);
    cout << "After change: " << endl;
    print_array(sample);
    return 0;
}