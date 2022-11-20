#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std; 

long aVeryBigSum(vector<long> ar) {
    long sum = 0;

    for (long a : ar)
        sum += a;
    return sum;
} 