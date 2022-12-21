#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int xCnt = 1;
    int notXCnt = 0;
    int start = 0;

    if (s.length() == 1)
        return 1;

    for (int i = start + 1; i < s.length(); i++)
    {
        if (s[start] == s[i])
            xCnt++;
        else
            notXCnt++;
        if (xCnt == notXCnt)
        {
            answer++;
            start = i + 1;
            i++;
            xCnt = 1;
            notXCnt = 0;
        }
        if (i == s.length() - 1)
            answer++;
    }

    return answer;
}