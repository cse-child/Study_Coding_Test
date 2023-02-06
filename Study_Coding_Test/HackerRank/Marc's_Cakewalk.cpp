#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;


long marcsCakewalk(vector<int> calorie) {
    long result = 0;

    sort(calorie.begin(), calorie.end(), greater<int>());

    for (int i = 0; i < calorie.size(); i++)
    {
        result += (pow(2, i) * calorie[i]);
    }
    return result;
}