#include <string>
#include <vector>

using namespace std;

// �� a���� �ָ� b���� �ݶ� �޴´�. �������� �ݶ� ���� n��
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
    // �ٸ�Ǯ��..
    //while(n >= a){
    //    answer += b;
    //    n -= (a - b);
    //}

    return answer;
}