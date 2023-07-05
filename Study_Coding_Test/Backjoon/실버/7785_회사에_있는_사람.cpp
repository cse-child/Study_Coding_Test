#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	map<string, int, greater<>> people; // �������� ����
	//map<string, int> people;

	for(int i = 0; i < N; i++)
	{
		string name, state;
		cin >> name >> state;

		if (state == "enter")
			people[name]++;
		else if (state == "leave")
			people[name]--;
	}

	/* map ��� */
	for(pair<string, int> p : people)
	{
		if (p.second > 0)
			cout << p.first << '\n';
	}

	/* map ���� ����ϱ� */
	//for (auto iter = people.rbegin(); iter != people.rend(); iter++)
	//{
	//	if (iter->second > 0)
	//		cout << iter->first << '\n';
	//}

	return 0;
}