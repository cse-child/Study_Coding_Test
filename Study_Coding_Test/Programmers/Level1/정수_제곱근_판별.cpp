#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    float answer = sqrt(n);
    if (pow(answer,2) == n)
        return pow(answer + 1,2);
    else
        return -1;
}

int main()
{
    solution(3);
}