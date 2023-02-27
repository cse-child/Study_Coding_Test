#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	int leftCnt = 0, rightCnt = 0;

	for (char word : s)
	{
		if (word == '(')
			leftCnt++;
		else if (word == ')')
		{
			rightCnt++;

			if (rightCnt > leftCnt) return false;
		}
	}

	return leftCnt == rightCnt ? true : false;
}