#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'minimumAbsoluteDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int minimumAbsoluteDifference(vector<int> arr) {
    int minDiff = abs(arr[0] - arr[1]);

    sort(arr.begin(), arr.end());

    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (minDiff > abs(arr[i] - arr[i + 1]))
            minDiff = abs(arr[i] - arr[i + 1]);
    }

    return minDiff;
}