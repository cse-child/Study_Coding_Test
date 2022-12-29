#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int pLen = p.length();

    for (int i = 0; i <= t.length() - pLen; i++)
    {
        long splitN = stol(t.substr(i, pLen));
        if (splitN <= stol(p))
            answer++;
    }
    return answer;
}