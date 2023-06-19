#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> card(N);
	for (int& c : card)
		cin >> c;

	int minDiff = M;
	int minSum = 0;
	int sum = 0;
	for(int i = 0; i < N-2; i++)
	{
		for(int j = i+1; j < N-1; j++)
		{
			for(int k = j+1; k < N; k++)
			{
				sum = card[i] + card[j] + card[k];
				if (M - sum >= 0 && M - sum < minDiff)
				{
					minDiff = M - sum;
					minSum = sum;
					cout << card[i] << " " << card[j] << " " << card[k] << endl;
				}
			}
		}
	}

	cout << minSum;
	return 0;
}


// ���Ʈ ����(������ ��,,)
// N �Է°��� ���� 1����� 1�ʷ� �����ؼ�
// ��� ����� ���� �� ����� �ð��� ���� �Ǻ�