#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int cnt = 0;
	for (int i = 0; i < discount.size(); i++)
	{
		bool bCheck = true;
		for (int j = 0; j < want.size(); j++)
		{
			if (count(discount.begin() + i, discount.begin() + i + 10, want[j]) < number[j])
			{
				bCheck = false;
				break;
			}
		}
		if (bCheck)
			cnt++;
	}
	return cnt;
}

int main()
{
	vector<string> want = { "banana", "apple", "rice", "pork", "pot" };
	vector<int> number = { 3,2,2,2,1 };
	vector<string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };

	//vector<string> want = { "apple" };
	//vector<int> number = { 10 };
	//vector<string> discount = { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" };

	cout << solution(want, number, discount);
}
