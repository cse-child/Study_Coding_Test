#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.resize(2);
    if (n > m)
    {
        int temp = n;
        n = m;
        m = temp;
    }
    answer[0] = gcd(n, m);
    answer[1] = (n * m) / answer[0];

    return answer;
}