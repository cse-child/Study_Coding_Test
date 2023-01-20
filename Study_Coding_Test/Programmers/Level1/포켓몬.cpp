#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    set<int> onlyNum(nums.begin(), nums.end());

    return min(nums.size() / 2, nums.size());

    /* ³» ÄÚµå
    map<int, int> onlyNum;

    for (int num : nums)
        onlyNum[num]++;

    return onlyNum.size() <= nums.size()*0.5 ? onlyNum.size() : nums.size()*0.5;
    */
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout << solution(nums);
}