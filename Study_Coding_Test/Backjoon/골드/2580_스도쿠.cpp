#include <iostream>
#include <string>

#define SIZE 9

using namespace std;

int puzzle[10][10];
int row[10][10];
int col[10][10];
int square[10][10];

int SquareNum(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}

bool DFS(int num)
{
	if(num == SIZE*SIZE)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				cout << puzzle[i][j] << ' ';
			cout << '\n';
		}
		return true;
	}

	int x = num / SIZE;
	int y = num % SIZE;

	if (puzzle[x][y] != 0)
		return DFS(num + 1);
	else
	{
		for(int i = 1; i <= SIZE; i++)
		{
			if(!row[x][i] && !col[y][i] && !square[SquareNum(x,y)][i])
			{
				row[x][i] = true;
				col[y][i] = true;
				square[SquareNum(x, y)][i] = true;
				puzzle[x][y] = i;

				if (DFS(num + 1))
					return true;

				row[x][i] = false;
				col[y][i] = false;
				square[SquareNum(x, y)][i] = false;
				puzzle[x][y] = 0;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cin >> puzzle[i][j];
			if (puzzle[i][j] != 0)
			{
				row[i][puzzle[i][j]] = true;
				col[j][puzzle[i][j]] = true;
				square[SquareNum(i,j)][puzzle[i][j]] = true;
			}
		}
	}

	DFS(0);

	return 0;
}