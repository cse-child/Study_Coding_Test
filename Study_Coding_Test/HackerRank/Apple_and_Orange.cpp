#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int appleCnt = 0;
    int orangeCnt = 0;

    for (int apple : apples)
    {
        if (apple + a >= s && apple + a <= t)
            appleCnt++;
    }

    for (int orange : oranges)
    {
        if (orange + b >= s && orange + b <= t)
            orangeCnt++;
    }
    cout << appleCnt << endl;
    cout << orangeCnt << endl;
}