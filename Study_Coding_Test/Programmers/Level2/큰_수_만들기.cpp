#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>
#include <stack>

using namespace std;

string solution(string number, int k) {
	string str = number;

	while(k > 0)
	{
		for (int i = 1; i < number.size(); i++)
		{
			if (number[i - 1] < number[i])
			{
				str[i - 1] = ' ';
				k--;

				if (k <= 0)
					break;
			}
		}
		number = regex_replace(str, regex(" "), "");
	}

	return regex_replace(str, regex(" "), "");
}

int main()
{
	//cout << solution("1924", 2);
	//cout << solution("1231234", 3);
	cout << solution("4177252841", 4);
}