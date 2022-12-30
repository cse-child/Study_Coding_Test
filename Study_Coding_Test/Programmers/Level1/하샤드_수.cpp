#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int digitSum = 0;
    int oriX = x;

    while (x != 0)
    {
        digitSum += x % 10;
        x /= 10;
    }
    
    return oriX % digitSum == 0;
}