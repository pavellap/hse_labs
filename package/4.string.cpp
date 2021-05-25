/**Дан массив слов.
 ** 1.Преобразовать исходный массив, вставив в каждое слово
длиной более 2 символов после второй буквы подстроку из двух начальных
букв этого же слова.
 ** 2. Удалить из всех слов массива все цифры.
 ** 3.Сформировать предложение из тех слов полученного массива, которые являются
«перевертышами». Слова в предложении должны быть упорядочены по
алфавиту.*/


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
void print_array(vector<T> array) {
    for (auto iterator = array.begin(); iterator != array.end(); iterator++) {
        cout << *iterator << " ";
    }
    cout << "" << endl;
}

/**
 * Function that descending sorts array of std::strings
 * @param array - array to sort
 * @returns void
 * */
void sort_array(vector<string> &array) {
    std::sort(array.begin(), array.end());
}

void to_uppercase(string &input) {
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
}

bool is_palindrome(string &word) {
    auto reversed = string(word.rbegin(), word.rend());
    to_uppercase(word);
    to_uppercase(reversed);
    return word == reversed;
}

void concat_strings(const vector<string> &array) {
    string base_string;
    for(const auto& iter : array) {
        base_string += (iter + " ");
    }
    cout << "GOT CONCATENATED STRING: " << endl;
}

string remove_numbers(string &word) {
    unsigned int helper = 0;
    for (auto i : word) {
        if (!std::isdigit(i)) {
            word[helper] = i;
            helper++;
        }
    }
    return word.substr(0, helper);
}

void first_task(vector<string> &input_array) {
    for (auto &iter : input_array) {
        if (iter.length() > 2) {
            iter.insert(0, iter, 0, 2);
        }
    }
    cout << "ARRAY AFTER INSERT: " << endl;
    print_array(input_array);
}

void second_task(vector<string> &input_array) {
    cout << "Array before erasing digits: " << endl;
    print_array(input_array);
    for (auto &word : input_array)
        word = remove_numbers(word);
    cout << "Array after removing digits" << endl;
    print_array(input_array);
}

void third_task(vector<string> &array) {
    vector<string> palindromes;
    for (auto &i : array) {
        if (is_palindrome(i))
            palindromes.push_back(i);
    }
    cout << "Array of palindromes: " << endl;
    print_array(palindromes);
    sort_array(palindromes);
    cout << "Array of palindromes after sort: " << endl;

    cout << "String of palindromes: " << endl;
    concat_strings(palindromes);
    print_array(palindromes);
}

int main() {

    vector<string> strings_set = {"I", "me", "sample", "VLADIVOSTOK 3000", "level", "He",
                                  "Honda 200", "aboBa", "raDar", "a", "mi12xe45dst83ing"};

    first_task(strings_set);

    second_task(strings_set);
    third_task(strings_set);
    return 0;
}