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

// isdigit(int c): �Ű������� ���� charŸ���� �������� �ƴ����� �Ǵ� 