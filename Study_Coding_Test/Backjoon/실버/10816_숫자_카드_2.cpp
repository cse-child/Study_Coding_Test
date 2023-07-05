#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	unordered_map<int, int> SangCard;

	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		SangCard[temp]++;
	}

	int M;
	cin >> M;
	vector<int> Card(M);
	for (int& c : Card)
		cin >> c;

	for(int i = 0; i < M; i++)
	{
		cout << SangCard[Card[i]] << ' ';
	}

	return 0;
}