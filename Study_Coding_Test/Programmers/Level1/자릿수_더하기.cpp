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
    //    // �� substr�� �ι�° ���ڴ� ������ �ε����� �ƴ϶� �ڸ� �ڸ����� ��Ÿ��!!!!
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