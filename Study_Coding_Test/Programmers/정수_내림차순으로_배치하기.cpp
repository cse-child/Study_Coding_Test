#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string answer = "";

    answer = to_string(n);
    sort(answer.begin(), answer.end(), greater<char>());

    //vector<int> digit;
    //while (n != 0)
    //{
    //    digit.push_back(n % 10);
    //    n /= 10;
    //}
    //
    //sort(digit.begin(), digit.end());
    //
    //for (int i = digit.size()-1; i >= 0 ; i--)
    //{
    //    answer += to_string(digit[i]);
    //}
    
    // �ڷ����� int�� �ƴ϶� long !!!!!!!!!!!!!!!
    return stoll(answer);
}

int main()
{
    solution(123456);
}