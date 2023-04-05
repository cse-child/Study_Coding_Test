#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void FindDivisor(vector<int>& out, int num)
{
	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			out.push_back(i);
			if (num / i != i)
				out.push_back(num / i);
		}
	}
	sort(out.begin(), out.end(), greater<int>());
}

vector<int> solution(int brown, int yellow) {
	vector<int> divisor;

	FindDivisor(divisor, brown + yellow);

	for (int i = 0; i < divisor.size(); i++)
	{
		for (int j = i; j < divisor.size(); j++)
		{
			if (brown == ((divisor[i] * 2) + (divisor[j] * 2) - 4)
				&& divisor[j] > 2
				&& yellow == (divisor[i] - 2) * (divisor[j] - 2))
			{
				return vector<int>{divisor[i], divisor[j]};
			}
		}
	}
	return vector<int>();
}