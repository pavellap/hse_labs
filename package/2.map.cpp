//
// Created by PLapshin on 3/1/2021.
//

#include <map>
#include <string>

using namespace std;

/**
 * Task:
 * Поступают сведения о том, какие ученики из какой школы на сколько
баллов сдали ЕГЭ. Требуется написать программу, которая выводит номера
школ, где средний балл больше среднего по району.*/

struct marks {
    size_t physics;
    size_t math;
    size_t russian_language;
};

int main() {
    using student = map<string, marks>;
    using school_structure = map<int, student>;

    marks my_marks = {78, 74, 91};
    student me;


    return 0;
}