/**Task:
 * Поступают сведения о том, какие ученики из какой школы на сколько
баллов сдали ЕГЭ. Требуется написать программу, которая выводит номера
школ, где средний балл больше среднего по району.*/

// assuming, that every student has 4 marks
#include <map>
#include <string>
#include <array>
#include <vector>
#include <time.h>
#include <any>
#include "utils.cpp"

using namespace std;


using student_marks = array<size_t, 4>;
using student = pair<string, student_marks>;
using school_structure = map<string, any>;


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

student_marks generate_marks() {
    student_marks marks;
    for (unsigned long long & mark : marks)
        mark = get_random_int_from_range(0, 100);
    return marks;
}

vector<student> generate_students(unsigned short length) {
    vector<student> result;
    for (int i = 0; i < length; i++) {
        student student_instance = {generate_name(), generate_marks()};
        result.push_back(student_instance);
    }
    return result;
}

float calc_average_score(const vector<student> &students) {
    float score = 0;
    for (auto i = students.begin(); i < students.end(); i++) {
        for (auto j = i->second.begin(); j < i->second.end(); j++) {
            score += *j;
        }

    }
    cout << "Calculated average score:  " << score / 4 / students.size() << endl;
    return score / 4 / students.size();
}

vector<school_structure> form_schools(unsigned short amount) {
    vector<school_structure> schools;
    for (unsigned int i = 0; i < amount; i++) {
        school_structure new_school;
        new_school["number"] = i;
        auto students = generate_students(50);
        new_school["students"] = students;
        new_school["average_score"] = calc_average_score(students);
        schools.push_back(new_school);
    }
    return schools;
}

float calc_average_between_schools(const vector<school_structure> &schools) {
    float result = 0;
    for (auto it = schools.begin(); it < schools.end(); it++) {
        result += any_cast<float>(it->at("average_score"));
    }

    return result / schools.size();
}



int main() {
    srand ( time(NULL) );
    setlocale(LC_ALL, "Russian");

    auto schools = form_schools(10);
    auto average_score = calc_average_between_schools(schools);
    cout << "GOT AVERAGE SCORE FOR ALL SCHOOLS: " << average_score << endl;

    for (auto i = schools.begin(); i < schools.end(); i++) {
        if (any_cast<float>(i->at("average_score")) > average_score) {
            cout << "School №" << any_cast<unsigned int>(i->at("number")) + 1
                    << " has score higher than average" << endl;
        }
    }

    return 0;
}