#include <iostream>
#include <string>

using namespace std;

int solution(int n)
{
    int answer = 0;
    //string strN = to_string(n);
    //
    //for (int i = 0; i < strN.length(); i++)
    //{
    //    // ★ substr의 두번째 인자는 마지막 인덱스가 아니라 자를 자릿수를 나타냄!!!!
    //    answer += stoi(strN.substr(i, 1));
    //}

    while (n != 0)
    {
        answer += n % 10;
        n /= 10;
    }

    return answer;
}

int main()
{
    solution(123);
}