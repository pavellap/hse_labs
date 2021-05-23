#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <cmath>
#include "utils.cpp"

using namespace std;


template<typename T>
void print_array(vector<T> array) {
    for (auto iterator = array.begin(); iterator != array.end(); iterator++) {
        cout << *iterator << " ";
    }
    cout << "" << endl;
}

vector<int> getIntegerVectorFromUser() {
    unsigned int length;
    cout << "Please, specify length of array: " << endl;
    cin >> length;
    vector<int> array;
    for (int i = 0; i < length; i++) {
        cout << "Input " << i + 1 << "th element:";
        int element;
        cin >> element;
        array.push_back(element);
    }
    return array;
}

vector<float> getFloatVectorFromUser(unsigned int length) {
    vector<float> array;
    for (int i = 0; i < length; i++) {
        cout << "Input " << i + 1 << "th element: ";
        float element;
        cin >> element;
        array.push_back(element);
    }
    return array;
}

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
        cout << "Found element multiple of 5" << endl << "Amount of elements before this element: " << counter << endl;
    return counter;
}

void second_part_second_task(vector<float> &array) {

    cout << "Please, input number K: " << endl;
    float k;
    cin >> k;
    cout << "Array before change:" << endl;
    print_array(array);
    cout << "So, we multiply elements, that equal to " << k << endl;
    transform(array.begin(), array.end(), array.begin(), [k](float &c) {
        return utils::compare_floats(c, k) ? c * 2 : c;
    });
    cout << "Array after change: " << endl;
    print_array(array);
}

void second_part_third_task(vector<float> &array) {
    if (array.size() >= 5) {
        cout << "Array before reverse: " << endl;
        print_array(array);
        reverse(array.begin(), array.begin() + 5);
        cout << "Array after reverse: " << endl;
        print_array(array);
    }
    else
        cout << "Array's length is shorter than 5, cannot perform action...";
}

void second_part_fourth_task(vector<float> &array) {
    vector<int> zeros;
    // push to zeros array indices of elements equal to zero
    for (int i = 0; i < array.size(); i++) {
        if (utils::compare_floats(array[i], 0))
            zeros.push_back(i);
    }

    if (zeros.empty()) {
        cout << "There are no elements that equal to 0 " << endl;
        return;
    }
    else {
        cout << "Array before change: " << endl;
        print_array(array);
        for (int item : zeros) {
            array.erase(array.begin() + item);
            array.push_back(0);
        }
        cout << "Array after change: " << endl;
        print_array(array);
    }

}

void second_part_fifth_task(vector<float> &array) {
    cout << "Array before change: " << endl;
    print_array(array);
    sort(array.begin(), max_element(array.begin(), array.end()));
    cout << "Array after change: " << endl;
    print_array(array);
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
            return "NO";
        }
    }
    return "YES";
}

void start_first_task() {
    cout << "------- FIRST PART -------" << endl;
    string answer;
    cout << "Do you want array to be generated automatically: (y/n)?" << endl;
    cin >> answer;
    if (answer == "y") {
        string another_answer;
        cout << "Do you want to generate array than matches conditions of first part of the task? (y/n)?" << endl;
        cin >> another_answer;
        vector<int> array;
        if (another_answer == "y")
            array = makeRandomVector(40, 0, 10000, true);
        else
            array = makeRandomVector();
        cout << "Okay, we generated this array for you: " << endl;
        print_array(array);
        cout << "Checking conditions of the first task..." << endl;
        cout << "The answer is: " << check_first_condition(array) << endl;
    } else {
        auto array = getIntegerVectorFromUser();
        cout << "You have created this array: " << endl;
        print_array(array);
        cout << "Checking conditions of the first task for your array... " << endl;

        cout << "The answer is: " << check_first_condition(array) << endl;
    }
}

void start_second_task() {
    cout << "------- SECOND PART -------" << endl;
    cout << "Please specify length of array: ";
    unsigned int size;
    cin >> size;
    string answer;
    cout << "Do you want array to be generated automatically: (y/n)?" << endl;
    cin >> answer;

    vector<float> array;

    if (answer == "y") {
        array = generate_real_array(size);
        cout << "We have generated this array with given length: " << endl;
        print_array(array);
    }
    else {
        array = getFloatVectorFromUser(size);
    }

    second_part_first_task(array);
    second_part_second_task(array);
    second_part_third_task(array);
    second_part_fourth_task(array);
    second_part_fifth_task(array);
}

int main() {
    /**1st part of the task*/
    start_first_task();

    /**
     * 2st part of the task
     * Дан массив из N вещественных чисел. Найти количество элементов, расположенных до первого элемента,
        кратного 5. Удвоить элементы массива, равные k. Если размер массива больше 4, то переставить первые 5
        элементов в обратном порядке. Перенести все нулевые элементы в конец массива, не меняя порядок
        следования остальных элементов. Отсортировать по возрастанию часть массива до первого максимального
        элемента
     *
     * */

    start_second_task();

    return 0;
}