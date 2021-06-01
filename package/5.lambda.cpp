/**
 * task: (2 30) (+2 ^2) (8 или 12)
 * */

#include <iostream>
#include <functional>

using namespace std;
const int start = 2, fin = 8; // Начальное и конечное числа
int main() {

    int stepsCount = 0;
    function<int(int, int, string)> calc = [&calc, &stepsCount]
            (int x, int fin, const string &way) {
        cout << "AVOKE FUNC: " << endl;
        stepsCount++;

        if (x < fin)
            return calc(x + 1, fin, way + " +1") + calc(x * 2, fin, way + " *2");

        else if (x == fin)
            return 1;

        return 0;
    };
    cout << "Forward\nCount: " << calc(start, fin, "") << endl;
    cout << stepsCount;
    return 0;
}