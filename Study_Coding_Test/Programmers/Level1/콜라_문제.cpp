#include <string>
#include <vector>

using namespace std;

// 빈병 a개를 주면 b개의 콜라를 받는다. 소유중인 콜라 빈병은 n개
int solution(int a, int b, int n) {
    int answer = 0;
    while (true)
    {
        int curN = ((n / a) * b);
        if (curN < 1)
            break;
        answer += curN;
        n = n - ((n / a) * a) + curN;
    }
    // 다른풀이..
    //while(n >= a){
    //    answer += b;
    //    n -= (a - b);
    //}

    return answer;
}