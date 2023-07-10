#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

#define SIZE 9

using namespace std;

int puzzle[SIZE][SIZE];
bool check[SIZE+1][SIZE+1];

bool CheckPuzzle(int x, int y)
{
	int xNum[10];
	int yNum[10];
	for(int i = 0; i < SIZE; i++)
	{
		xNum[puzzle[x][i]]++;
		yNum[puzzle[i][y]]++;
	}

	for(int i = 1; i < 10; i++)
	{
		if (xNum[i] > 1 || yNum[i] > 1)
			return false;
	}

	return true;
}

void DFS(int depth)
{
	if(depth == SIZE)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				cout << puzzle[i][j] << ' ';
			cout << '\n';			
		}
		return;
	}

	for(int i = 0; i < SIZE; i++)
	{
		if(puzzle[depth][i] == 0)
		{
			for(int j = 1; j < SIZE+1; j++)
			{
				puzzle[depth][i] = j;

			}
		}
	}


	//for(int i = 0; i < SIZE; i++)
	//{
	//	if(puzzle[depth][i] == 0)
	//	{
	//		for(int j = 1; j < SIZE+1; j++)
	//		{
	//			if(!check[depth][j])
	//			{
	//				check[depth][j] = true;
	//				puzzle[depth][i] = j;
	//			}
	//		}
	//		DFS(depth + 1);
	//		//check[depth][j] = false;
	//	}
	//}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> puzzle[i][j];
			if (puzzle[i][j] != 0)
				check[i][puzzle[i][j]] = true;
		}
	}

	cout << endl << endl;
	DFS(0);

	return 0;
}