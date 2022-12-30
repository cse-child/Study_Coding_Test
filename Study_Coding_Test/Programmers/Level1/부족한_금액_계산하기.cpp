using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = money;

    for (int i = 1; i <= count; i++)
        answer -= (price * i);

    return answer >= 0 ? 0 : (answer * -1);
}
// 시그마 공식-1부터 n까지의 합: n*(n+1)/2