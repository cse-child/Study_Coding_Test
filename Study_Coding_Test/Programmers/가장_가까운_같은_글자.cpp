#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = -1;
        for (int j = i - 1, k = 1; j >= 0; j--, k++)
        {
            if (s[i] == s[j])
            {
                idx = k;
                break;
            }
        }
        answer.push_back(idx);
    }
    return answer;
}