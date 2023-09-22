#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitStringToVector(const string& str)
{
	vector<string> v;
	for (int i = 1; i < str.length(); i++)
	{
		char a = toupper(str[i - 1]);
		char b = toupper(str[i]);

		string temp = "";
		if ((a >= 'A' && a <= 'Z') && (b >= 'A' && b <= 'Z'))
		{
			temp += a;
			temp += b;

			v.emplace_back(temp);
		}
	}
	return v;
}

// 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값
// 모두 공집합일 경우에는 J(A, B) = 1
int solution(string str1, string str2) {
	int answer = 0;

	vector<string> strv1 = SplitStringToVector(str1);
	vector<string> strv2 = SplitStringToVector(str2);

	sort(strv1.begin(), strv1.end());
	sort(strv2.begin(), strv2.end());

	vector<string> resultI(3000);
	vector<string> resultU(3000);
	auto iter1 = set_intersection(strv1.begin(), strv1.end(), strv2.begin(), strv2.end(), resultI.begin());
	auto iter2 = set_union(strv1.begin(), strv1.end(), strv2.begin(), strv2.end(), resultU.begin());
	resultI.erase(iter1, resultI.end());
	resultU.erase(iter2, resultU.end());

	if (resultI.size() == 0 && resultU.size() == 0) return 65536;

	float r = (float)resultI.size() / resultU.size();
	return r * 65536;
}

int main()
{
	//cout << solution("FRANCE", "french");
	//cout << solution("handshake", "shake hands");
	cout << solution("E=M*C^2", "e=m*c^2");
}