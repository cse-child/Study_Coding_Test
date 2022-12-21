#include <string>
#include <vector>
#include <iostream>

using namespace std;

int GetDivisorCnt(int num)
{
    int count = 0;

    // 20�� ��� ���ϱ�
    for (int i = 1; i * i <= num; i++)
    {
        if (i * i == num)
            count++; // ���: i
        else if (num % i == 0) // 1,20 / 2,10 / 4,5
            count += 2; // ���: i, num/i
    }
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        int divisor = GetDivisorCnt(i);
        if (divisor > limit)
            answer += power;
        else
            answer += GetDivisorCnt(i);
    }
    return answer;
}