#include <string>
#include <vector>
#include <iostream>

using namespace std;

string ChangeBinaryNum(int num)
{
    string result = "";

    while (num >= 1)
    {
        result = to_string(num % 2) + result;
        num /= 2;
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer(2);

    while (s != "1")
    {
        int removeCnt = 0;
        for (char c : s)
        {
            if (c == '0')
                removeCnt++;
        }
        s = ChangeBinaryNum(s.size() - removeCnt);
        answer[0]++;
        answer[1] += removeCnt;
    }

    return answer;
}