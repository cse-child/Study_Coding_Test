#include <string>
#include <vector>

using namespace std;

vector<int> GetBinaryNumber(int num, int length)
{
	vector<int> result(length, 0);

	for (int i = 0; i < length; i++)
	{
		result[length - i - 1] = num % 2;
		num /= 2;

		if (num < 0)
			result[length - i] = 0;
	}
	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (GetBinaryNumber(arr1[i], n)[j] == 1 || GetBinaryNumber(arr2[i], n)[j] == 1)
				answer[i] += "#";
			else
				answer[i] += " ";
		}
	}

	return answer;
}