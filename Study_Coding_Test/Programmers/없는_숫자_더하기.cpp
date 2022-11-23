#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    //int answer = 45;
    //for (int num : numbers)
    //    answer -= num;
    //return answer;

    return 45 - accumulate(numbers.begin(), numbers.end(), 0);
}

int main()
{

}