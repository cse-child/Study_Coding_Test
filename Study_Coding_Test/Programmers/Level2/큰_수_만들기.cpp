#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>
#include <stack>

using namespace std;

string solution(string number, int k) {
	stack<char> st;
	string str = "";
	bool isPoped = false;

	st.push(number[0]);

	for(int i = 1; i < number.size(); i++)
	{
		if(st.top() < number[i])
		{
			while (!st.empty() && st.top() < number[i] && k > 0)
			{
				st.pop();
				isPoped = true;
				k--;
			}
		}
		st.push(number[i]);

		if (k <= 0)
		{
			if (i == number.size() - 1) break;
				
			for (int j = i+1; j < number.size(); j++)
				st.push(number[j]);

			break;
		}
	}

	if (!isPoped)
		return number.substr(0, number.size() - k);
	
	while(!st.empty())
	{
		str += st.top();
		st.pop();
	}
	reverse(begin(str), end(str));

	return str;
}

int main()
{
	//cout << solution("1924", 2); //94
	//cout << solution("1231234", 3); //3234
	//cout << solution("4177252841", 4); // 775841
	//cout << solution("93939", 3); //99
	//cout << solution("9437227", 4); //977
	cout << solution("4321", 1); //432

	string str = "1234";
	cout << endl << str.substr(0, str.size()-2);
}

/*

string solution(string number, int k) {
	string str = number;

	while(k > 0)
	{
		for (int i = 1; i < number.size(); i++)
		{
			if (number[i - 1] <= number[i])
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
 
 */