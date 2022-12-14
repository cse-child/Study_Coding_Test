#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    for (int i = 0, j = 0; i < s.length(); i++, j++)
    {
        if (s[i] == ' ')
        {
            answer += " ";
            j = -1;
            continue;
        }
        if (j % 2 == 0)
            answer += toupper(s[i]);
        else
            answer += tolower(s[i]);
    }
    return answer;
}