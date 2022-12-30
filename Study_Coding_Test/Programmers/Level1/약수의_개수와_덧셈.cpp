#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++)
    {
        int divisorCnt = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                divisorCnt++;

        }
        if (divisorCnt % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}