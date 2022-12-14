#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (!(s.length() == 4 || s.length() == 6))
        return false;
    for (char word : s)
    {
        if (word < '0' || word > '9')
            return false;
    }
    return true;
}

// isdigit(int c): 매개변수로 들어온 char타입이 숫자인지 아닌지를 판단 