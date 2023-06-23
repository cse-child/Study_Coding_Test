#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int N;
int arr[16];
int cnt = 0;

void DFS(int depth)
{
	if (depth == N)
	{
		cnt++;
		//for (int i = 0; i < N; i++)
		//	cout << arr[i] << " ";
		//cout << endl << "count : " << cnt << endl;
		return;
	}
	
	for (int i = 0; i < N; i++)
	{
		bool check = true;
		//for (int j = 0, k = depth-1; j < depth; j++, k--)
		for (int j = 0; j < depth; j++)
		{
			// ���� Depth�������� ���� �� ĭ�� �ö󰡸� �밢�� �Ǻ�
			//if (arr[depth - j - 1] == i || abs(arr[depth - j - 1] - i) == abs(depth-k))
			//{
			//	check = false;
			//	break;
			//}

			// ù��° �ٺ��� �� ĭ�� �������� �밢�� �Ǻ�
			if(arr[j] == i || abs(arr[j] - i) == abs(depth-j))
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			arr[depth] = i;
			DFS(depth + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	DFS(0);

	cout << cnt;
	return 0;
}
