#include <string>
#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int main()
{
	string s, t;
	cin >> s >> t;

	if(s.size() > t.size())
	{
		string temp = s;
		s = t;
		t = temp;
	}

	int lcm = (s.size() * t.size()) / GCD(s.size(), t.size());

	string tempS, tempT;
	for (int i = 0; i < lcm / s.size(); i++)
		tempS += s;

	for (int j = 0; j < lcm / t.size(); j++)
		tempT += t;

	if (tempS == tempT)
		cout << "1";
	else
		cout << "0";
	return 0;
}