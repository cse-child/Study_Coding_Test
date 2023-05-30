#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	vector<int> result;
	string A, B;
	
	cin >> A >> B;

	// A를 (자릿수가)더 큰수로 변경
	if(A.length() < B.length())
	{
		string temp = A;
		A = B;
		B = temp;
	}

	vector<int> aNum(A.length());
	vector<int> bNum(A.length());

	for(int i = 0; i < aNum.size(); i++)
	{
		aNum[i] = A[i] - '0';
		if (i < B.size())
			bNum[A.size()-B.size()+i] = B[i] - '0';
	}

	//cout << "A : " << A << endl;
	//cout << "B : " << B<< endl;

	for(int i = aNum.size()-1; i >= 0; i--)
	{
		int sum = aNum[i] + bNum[i];
		if (sum >= 10)
		{
			sum -= 10;
			if (i - 1 < 0)
			{
				result.push_back(sum);
				result.push_back(1);
				break;
			}
			aNum[i - 1]++;
		}
		result.push_back(sum);
	}

	reverse(result.begin(), result.end());

	for (int num : result)
		cout << num;
	cout << endl;

	return 0;
}