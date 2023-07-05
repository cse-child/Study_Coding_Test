#include <iostream>
#include <string>

using namespace std;

// ¿À.. 12ºÐÄÆ
int N;
int Square[129][129];
int result[2];

void CheckSquare(int length, int startX, int startY)
{
	int first = Square[startX][startY];
	for(int x = startX; x <startX+length; x++)
	{
		for(int y = startY; y < startY+length; y++)
		{
			if(Square[x][y] != first)
			{
				CheckSquare(length / 2, startX, startY);
				CheckSquare(length / 2, startX, startY + (length / 2));
				CheckSquare(length / 2, startX + (length / 2), startY);
				CheckSquare(length / 2, startX + (length / 2), startY + (length / 2));
				return;
			}
		}
	}
	result[first]++;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for(int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			cin >> Square[x][y];

	CheckSquare(N, 0, 0);

	cout << result[0] << '\n' << result[1];
	return 0;
}