#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> RemoveBlock;
int answer = 0;
 
bool Check4Block(const vector<string>& board, int x, int y)
{
	if (board[x][y] == ' ') return false;
	if (x >= board.size()-1 || y >= board[0].size()-1) return false;

	int moveX[3] = { 0, 1, 1 };
	int moveY[3] = { 1, 0, 1 };
	for(int i = 0; i < 3; i++)
		if (board[x][y] != board[x + moveX[i]][y + moveY[i]]) return false;

	RemoveBlock[x][y] = true;
	for (int i = 0; i < 3; i++)
		RemoveBlock[x + moveX[i]][y + moveY[i]] = true;

   	return true;
}

void RemoveBlocks(vector<string>& board)
{
	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[i].size(); j++)
		{
			if (RemoveBlock[i][j])
			{
				board[i][j] = ' ';
				answer++;
			}
		}
	}
	fill(RemoveBlock.begin(), RemoveBlock.end(), vector<bool>(board[0].size(), false));
}

void DownBlock(vector<string>& board, int x, int y)
{
	int tempX = x+1;
	bool move = false;

	while(board[tempX][y] == ' ')
	{
		tempX++;
		move = true;
		if (tempX >= board.size()) break;
	}

	if(move)
	{
		board[tempX - 1][y] = board[x][y];
		board[x][y] = ' ';
	}
}

void RefreshBoard(vector<string>& board)
{
	for(int i = board.size()-2; i >= 0; i--)
	{
		for(int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j] != ' ')
				DownBlock(board, i, j);
		}
	}
}

int solution(int m, int n, vector<string> board) {

	RemoveBlock.resize(m);
	for (vector<bool>& c : RemoveBlock)
		c.resize(n);

	while(true)
	{
		bool refresh = false;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (Check4Block(board, i, j))
					refresh = true;

		if (refresh)
		{
			RemoveBlocks(board);
			RefreshBoard(board);
		}
		else
			break;
	}
	return answer;
}

int main()
{
	//vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	//cout << solution(4, 5, board);

	vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
	cout << solution(6, 6, board);
}