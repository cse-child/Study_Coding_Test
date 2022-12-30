#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    vector<int> nums;
    stringstream ss(s);

    string temp;
    while (getline(ss, temp, ' '))
        nums.push_back(stoi(temp));

    sort(nums.begin(), nums.end());

    return to_string(nums[0]) + " " + to_string(nums[nums.size() - 1]);
}