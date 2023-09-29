#include <vector>
#include <iostream>

using namespace std;

bool IsPrime(int a, int b, int c)
{
    int num = a + b + c;
    
    if (num <= 1) return false;

    for (int i = 2; i < num/2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i+1; j < nums.size() - 1; j++)
        {
            for (int k = j+1; k < nums.size(); k++)
            {
                if (IsPrime(nums[i], nums[j], nums[k]))
                    answer++;
            }
        }
    }
    return answer;
}

int main()
{
    //vector<int> nums = { 1,2,3,4 };
    vector<int> nums = { 1,2,7,6,4 };
    cout << solution(nums);
}