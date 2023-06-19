#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int FixChessBoard(vector<vector<char>>& board, int x, int y)
{
	int wCnt = 0, bCnt = 0;
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(j % 2 == 0)
			{
				if(i % 2 == 0)
				{
					if (board[x + i][y + j] == 'B')
						wCnt++;
					else
						bCnt++;
				}
				else
				{
					if (board[x + i][y + j] == 'W')
						wCnt++;
					else
						bCnt++;
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					if (board[x + i][y + j] == 'W')
						wCnt++;
					else
						bCnt++;
				}
				else
				{
					if (board[x + i][y + j] == 'B')
						wCnt++;
					else
						bCnt++;
				}
			}
		}
	}
	return wCnt < bCnt ? wCnt : bCnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<char>> chess(N, vector<char>(M));
	for(vector<char>& row : chess)
		for (char& col : row)
			cin >> col;


	int min = FixChessBoard(chess, 0, 0);
	for(int i = 0; i < chess.size()-7; i++)
	{
		for(int j = 0; j < chess[i].size()-7; j++)
		{
			int temp = FixChessBoard(chess, i, j);
			min = min > temp ? temp : min;
		}
	}

	cout << min;

	return 0;
}