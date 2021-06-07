#include <iostream>
#include <string>
#include <set>
#include <stdio.h>

using namespace std;

bool FSM(char ch, int &S) {
    switch (S) {
        case 0:
            if (ch == 'w') {
                S = 1;
                return false;
            }
            S = -1;
            return true;
        case 1:
            if (ch == 'h') {
                S = 2;
                return false;
            }
            S = -1;
            return true;
        case 2:
            if (ch == 'i') {
                S = 3;
                return false;
            }
            S = -1;
            return true;
        case 3:
            if (ch == 'l') {
                S = 4;
                return false;
            }
            S = -1;
            return true;
        case 4:
            if (ch == 'e') {
                S = 5;
                return false;
            }

            S = -1;
            return true;
        case 5:
            if (ch == '(') {
                S = 6;
                return false;
            }
            S = -1;
            return true;
        case 6:
            if (ch >= '0' && ch <= '9') {
                S = 7;
                return false;
            }
            switch (ch)
                S = -1;
            return true;
        case 7:
            switch (ch) {
                case 0 ... 9:
                    S = 7;
                    return false;
                case '!':
                case '=':
                    S = 10;
                    return false;
                case '<':
                case '>':
                    S = 11;
                    return false;
                case '.':
                    S = 8;
                    return false;
                default:
                    S = -1;
                    return true;
            }
        case 8:
            if (ch >= '0' && ch <= '9') {
                S = 9;
                return false;
            }
            S = -1;
            return true;
        case 9:
            switch (ch) {
                case 0 ... 9:
                    S = 9;
                    return false;
                case '!':
                case '=':
                    S = 10;
                    return false;


                case '<':
                case '>':
                    S = 11;
                    return false;
                default:
                    S = -1;
                    return true;
            }
        case 10:
            if (ch == '=') {
                S = 11;
                return false;
            }
            S = -1;
            return true;
        case 11:
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
                S = 12;
                return false;
            }
            S = -1;
            return true;
        case 12:
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
                S = 12;
                return false;
            }
            if (ch == ')') S = 13;
            return false;
            S = -1;
            return true;
        case 13:
            break;
    }
}

int main() {
    int S = 0;
    string str;
    set<int> Final = {13}; // Множество конечных состояний автомата
    bool FEnter = false;
    while (getline(cin, str), str != "") {
        if (!FEnter)


            FEnter = true;
        else
            FSM('\n', S);
        for (auto i: str)
            if (FSM(i, S)) break;
    }
    cout << S << endl;
    if (Final.count(S)) // Проверяем, находится ли автомат в конечном состоянии
        cout << "Yes";
    else
        cout << "No";
    return 0;
}