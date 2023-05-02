#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

bool IsPrime(int n)
{
	if (n <= 1) return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}


int solution(string numbers) {
	set<int> nums;

	sort(numbers.begin(), numbers.end());

	do
	{
		string temp = "";
		for (char num : numbers)
		{
			temp += num;
			if (IsPrime(stoi(temp)))
				nums.insert(stoi(temp));
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	return nums.size();
}