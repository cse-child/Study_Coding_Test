#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int num) {
    string answer = "Odd";
    if (num % 2 == 0) {
        answer = "Even";
    }
    return answer;
}

int main(void)
{
    cout << solution(3);
}