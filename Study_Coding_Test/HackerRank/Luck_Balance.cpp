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
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */

int luckBalance(int k, vector<vector<int>> contests) {
    int resultScore = 0;

    vector<int> importantTests; // 중요한 문제

    for (vector<int> contest : contests)
    {
        if (contest[1]) // 중요한 문제
        {
            importantTests.push_back(contest[0]);
        }
        else // contest[1] == 0
        {
            resultScore += contest[0]; // 안중요한 문제는 무조건 맞춤
        }
    }

    sort(importantTests.begin(), importantTests.end(), greater<int>());

    for (int i = 0; i < importantTests.size(); i++)
    {
        if (i < k)
            resultScore += importantTests[i];
        else
            resultScore -= importantTests[i];
    }

    return resultScore;
}