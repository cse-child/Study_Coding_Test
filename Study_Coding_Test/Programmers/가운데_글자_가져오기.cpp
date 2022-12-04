#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if (s.length() % 2 == 0)
        answer = s.substr((s.length() / 2) - 1, 2);
    else
        answer = s.substr((s.length() / 2), 1);

    return answer;

    // È¦Â¦ °Ë»çÇÒ ¶§ s.length() & 1 == 1ÀÌ¸é Â¦¼ö
}