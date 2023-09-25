#include <vector>

using namespace std;

vector<int> answer(2);

void QuadTree(const vector<vector<int>>& arr, int size, int x, int y)
{
	for(int i = x; i < x+size; i++)
	{
		for(int j = y; j < y+size; j++)
		{
			if (arr[x][y] != arr[i][j])
			{
				QuadTree(arr, size / 2, x, y);
				QuadTree(arr, size / 2, x + size / 2, y);
				QuadTree(arr, size / 2, x, y + size / 2);
				QuadTree(arr, size / 2, x + size / 2, y + size / 2);

				return;
			}
		}
	}
	answer[arr[x][y]] += 1;
}

vector<int> solution(vector<vector<int>> arr) {

	QuadTree(arr, arr.size(), 0, 0);

	return answer;
}

int main()
{
	vector<vector<int>> arr = { {1,1,0,0} ,{1,0,0,0} ,{1,0,0,1} ,{1,1,1,1} };
	solution(arr);
}