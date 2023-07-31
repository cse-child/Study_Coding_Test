#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	string numStr = "";
	int result = 0;
	bool isMinus = false;
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+' || i == str.size())
		{
			if (isMinus)
			{
				result -= stoi(numStr);
				numStr = "";
			}
			else
			{
				result += stoi(numStr);
				numStr = "";
			}
		}
		else // 숫자라면 누적 더하기
			numStr += str[i];

		if (str[i] == '-')
			isMinus = true;
	}

	cout << result;

	return 0;
}