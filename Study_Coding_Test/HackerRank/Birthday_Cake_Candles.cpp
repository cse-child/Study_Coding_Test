#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int birthdayCakeCandles(vector<int> candles) {
    sort(candles.begin(), candles.end(), greater<int>());
    int maxNum = candles[0];
    int count = 0;

    for (int i = 1; i <= candles.size(); i++)
    {
        if (candles[i] != maxNum)
        {
            count = i;
            break;
        }
    }
    return count;
}