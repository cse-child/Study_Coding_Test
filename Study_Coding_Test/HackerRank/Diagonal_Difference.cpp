#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int diagonalSum1 = 0;
    int diagonalSum2 = 0;

    for (int i = 0, bIdx = arr.size() - 1; i < arr.size(); i++)
    {
        diagonalSum1 += arr[i][i];
        diagonalSum2 += arr[i][bIdx--];
    }
    return abs(diagonalSum1 - diagonalSum2);
}