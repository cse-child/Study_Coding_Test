#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	set<string> arr;
	string str;
	cin >> str;

	//for (int i = 0; i < str.length(); i++)
	//{
	//	for (int j = 0; j < str.length() - i; j++)
	//	{
	//		string temp = str.substr(j, i + 1);
	//		cout << temp << endl;
	//		arr.insert(temp);
	//	}
	//}

	for(int i = 0; i < str.size(); i++)
	{
		string temp = "";
		for(int j = i; j < str.size(); j++)
		{
			temp += str[j];
			cout << temp << endl;
		}
	}

	cout << arr.size();

	return 0;
}