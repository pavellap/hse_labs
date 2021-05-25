/** Параметры варианта 17. 1 3 2 6 4
 *
 * 1. Способ задания: Ввод с консоли
 * 2. Способ выбора элементов множества A: Четные по значению элементы универсального множества
 * 3. Способ выбора элементов множества B: Cлучайным образом
 * (случайным образом выбираются индексы  универсального множества)
 * 4. Преобразования над множествами: A\B и A∪B ∩ /(A∩B)
 * 5. Вывод результата: Четные по индексу элементы
 *
 * */

#include <set>
#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;


int get_random_number(int right_range) {
    return rand() % right_range;
}


template<typename T>
void print_set(set<T> set) {
    for (auto iterator = set.begin(); iterator != set.end(); iterator++) {
        cout << *iterator << " ";
    }
    cout << "" << endl;
}

bool is_number(const string &input) {
    return std::all_of(input.begin(), input.end(), [](char i) {
        return std::isdigit(i) != 0;
    });
}

set<int> form_universal_set() {
    set<int> target;
    cout << "Please, input elements of set." << endl;
    cout << "Input empty string if you want to stop: " << endl;
    string input;
    while (true) {
        if (not std::getline(std::cin, input) or input.empty()) break;
        if (is_number(input))
            target.insert(std::stoi(input));
        else
            cout << "Please, input valid number..." << endl;
    }
    return target;
}

set<int> form_set_a(const set<int> &universal_set) {
    set<int> target;

    for (int iter : universal_set) {
        if (iter % 2 == 0)
            target.insert(iter);
    }

    return target;
}

set<int> form_set_b(const set<int> &universal_set) {
    set<int> target;
    // getting amount of elements for set B
    auto amount = uniform_int_distribution<>(0, universal_set.size());

    int i = 0;
    while (i < universal_set.size()) {
        // get random index from universal set
        int seed = get_random_number(universal_set.size());
        target.insert(*std::next(universal_set.begin(), seed));
        i++;
    }

    return target;
}

void calc_new_set(const set<int> &a_set, const set<int> &b_set) {
    // A\B и A∪B ∩ /(A∩B)
    set<int> first_set;
    set<int> second_set;
    set<int> buffer_first;
    set<int> buffer_second;
    set<int> buffer_third;

    set_symmetric_difference(a_set.begin(), a_set.end(),
                             b_set.begin(), b_set.end(), inserter(first_set, first_set.begin()));
    set_intersection(a_set.begin(), a_set.end(),
                     b_set.begin(), b_set.end(), inserter(buffer_first, buffer_first.begin()));
    set_union(a_set.begin(), a_set.end(),
              b_set.begin(), b_set.end(), inserter(buffer_second, buffer_second.begin()));
    set_difference(buffer_first.begin(), buffer_first.end(),
                   buffer_second.begin(), buffer_second.end(), inserter(buffer_third, buffer_third.begin()));
    set_intersection(buffer_first.begin(), buffer_first.end(),
                     buffer_third.begin(), buffer_third.end(), inserter(second_set, second_set.begin()));
    cout << "FIRST TARGET: " << endl;
    print_set(first_set);
    cout << "SECOND TARGET: " << endl;
    print_set(second_set);
}

int main() {


    srand(time(NULL));

    auto base = form_universal_set();
    cout << "GOT SET: " << endl;
    print_set(base);
    cout << "SET A: " << endl;
    auto set_a = form_set_a(base);
    print_set(set_a);
    auto set_b = form_set_b(base);
    cout << "SET B: " << endl;
    print_set(set_b);

    calc_new_set(set_a, set_b);

    cout << endl;

    /*print_set(set_a);

    print_set(set_b);*/

    return 0;
}
