#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int lastIdx = -1;

    sort(score.begin(), score.end(), greater<int>());

    while (true)
    {
        lastIdx += m;

        if (lastIdx > score.size() - 1) break;

        answer += (score[lastIdx] * m);
    }
    return answer;
}