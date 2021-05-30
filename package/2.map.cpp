/**Task:
 * Поступают сведения о том, какие ученики из какой школы на сколько
баллов сдали ЕГЭ. Требуется написать программу, которая выводит номера
школ, где средний балл больше среднего по району.*/

#include <map>
#include <string>
#include <array>
#include <vector>
#include <time.h>
#include "utils.cpp"

using namespace std;


// assuming, that every student has 4 marks
using student = pair<string, array<int, 4>>;
using school_structure = map<int, vector<student>>;


const vector<string> males_names = {"Павел", "Александр", "Максим", "Фёдор", "Юрий", "Евгений", "Сергей", "Артём", "Михаил"};
const vector<string> females_names = {"Мария", "Наталья", "Дарья", "Валентина", "Алина", "Александра"};
const vector<string> last_names = {"Минин", "Попов", "Александров", "Иванов", "Михайлов", "Муравьёв", "Миночкин"};


template<typename T>
T get_random_element_from_array(const vector<T> &array) {
    return array[rand() % array.size()];
}

unsigned short get_random_int_from_range(short min, short max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

string generate_name() {
    auto seed = get_random_int_from_range(0 ,1);
    if (seed == 0)
        return get_random_element_from_array(last_names) + " " + get_random_element_from_array(males_names);
    return get_random_element_from_array(last_names) + "а " + get_random_element_from_array(females_names);
}

array<int, 4> generate_marks() {
    array<int, 4> result{};
    for (int i = 0; i < 4; i++)
        result[i] = get_random_int_from_range(0, 100);
    return result;
}

vector<student> generate_students(unsigned short length) {
    vector<student> result;
    for (int i = 0; i < length; i++) {
        student student_instance = {generate_name(), generate_marks()};
        result.push_back(student_instance);
    }
    return result;
}

int main() {
    srand ( time(NULL) );
    setlocale(LC_ALL, "Russian");

    auto students = generate_students(50);
    for (auto i = students.begin(); i < students.end(); i++) {
        cout << "Student name: " << i->first << endl;
        cout << "Student marks: ";
        utils::print_array(i->second);
    }

    //utils::print_array(students);

    return 0;
}