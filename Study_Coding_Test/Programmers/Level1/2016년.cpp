#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string dayOfWeek[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    int days[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int totalDay = b;

    for (int i = 0; i < a - 1; i++)
        totalDay += days[i];

    return dayOfWeek[(totalDay + 4) % 7];
}