#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> result;
    result.resize(100);

    for (int num : arr)
        result[num]++;

    return result;
}