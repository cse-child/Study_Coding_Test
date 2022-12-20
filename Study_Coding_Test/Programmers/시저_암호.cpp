#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (char word : s)
    {
        if (word == ' ')
        {
            answer += " ";
            continue;
        }
        int addC = word + n;

        if ((word <= 'Z' && addC > 'Z') || addC > 'z')
            answer += (char)(addC - 26);
        else
            answer += (char)addC;
    }

    return answer;
}