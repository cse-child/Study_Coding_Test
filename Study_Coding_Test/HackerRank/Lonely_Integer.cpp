#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lonelyinteger(vector<int> a) {
    unordered_map<int, int> nums;
    for (int num : a)
        nums[num]++;

    for (pair<int, int> num : nums)
    {
        if (num.second == 1)
            return num.first;
    }

    return 0;
}
