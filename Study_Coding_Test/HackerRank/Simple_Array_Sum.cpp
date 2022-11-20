#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int simpleArraySum(vector<int> ar) {
    int sum = 0;
    for (int num : ar)
        sum += num;
    return sum;
}