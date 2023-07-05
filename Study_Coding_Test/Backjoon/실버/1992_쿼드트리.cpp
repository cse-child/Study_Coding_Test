#include <iostream>
#include <string>

using namespace std;

int N;
char arr[65][65];

void CheckQuadTree(int length, int x, int y)
{
	char dot = arr[x][y];
	for(int i = x; i < x+length; i++)
	{
		for(int j = y; j < y+length; j++)
		{
			if(arr[i][j] != dot)
			{
				cout << "(";
				CheckQuadTree(length / 2, x, y);
				CheckQuadTree(length / 2, x, y+ length / 2);
				CheckQuadTree(length / 2, x+ length / 2, y);
				CheckQuadTree(length / 2, x+ length / 2, y+ length / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << to_string(dot);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	
	CheckQuadTree(N, 0, 0);
	return 0;
}