#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> yNums;
    vector<char> pairNums;

    // string to map
    for (int i = 0; i < Y.length(); i++)
        yNums[Y[i]]++;

    for (int i = 0; i < X.length(); i++)
    {
        if (yNums[X[i]] > 0)
        {
            pairNums.push_back(X[i]);
            yNums[X[i]]--;
        }
    }

    sort(pairNums.begin(), pairNums.end(), greater<char>());

    for (char num : pairNums)
        answer += num;

    if (answer == "") return "-1";
    // ★stoll(answer) == 0 으로 풀면 범위 초과 에러 발생!!!!!!!!!!!
    if (answer[0] == '0') return "0";

    return answer;
}

int main(void)
{
    solution("123123123123123123123123123123123123123123123123", "123123123123123123123123123123123123123123");
}