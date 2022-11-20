#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void miniMaxSum(vector<int> arr) {
    long sum = 0;
    for (int num : arr)
        sum += num;

    sort(arr.begin(), arr.end(), greater<int>());

    cout << sum - arr[0] << " ";
    cout << sum - arr[arr.size() - 1];
}