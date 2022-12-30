#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int pCnt = 0, yCnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char c = tolower(s[i]);
        if (c == 'p')
            ++pCnt;
        else if (c == 'y')
            ++yCnt;
    }

    return pCnt == yCnt;
}