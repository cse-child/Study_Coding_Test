#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void FindDivisor(vector<int>& out, int num)
{
	for (int i = 1; i < num / 4; i++)
	{
		if (num % i == 0)
		{
			out.push_back(i);
			out.push_back(num / i);
		}
	}
	sort(out.begin(), out.end());
	for (int i = 0; i < out.size(); i++)
		cout << out[i] << " ";
}

vector<int> solution(int brown, int yellow) {
	vector<int> answer(2);
	vector<int> divisor;

	FindDivisor(divisor, brown*yellow);

	for (int i = 0; i < divisor.size(); i++)
	{
		for (int j = i + 1; j < divisor.size(); j++)
		{

		}
	}

	return answer;
}