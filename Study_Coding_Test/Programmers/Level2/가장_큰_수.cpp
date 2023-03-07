#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(int num1, int num2)
{
	string num_str1 = to_string(num1);
	string num_str2 = to_string(num2);

	return stoi(num_str1 + num_str2) > stoi(num_str2 + num_str1);
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), comp);
	bool allZero = true;
	for (int num : numbers)
	{
		answer += to_string(num);
		if (num != 0) allZero = false;
	}

	return allZero ? "0" : answer;
}