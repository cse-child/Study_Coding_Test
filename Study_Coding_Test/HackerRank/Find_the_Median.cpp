#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());

    return arr[(int)arr.size() / 2];
}