#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 1;
	int curWeight = 0;
	int passTruck = 0;

	vector<int> trucks(truck_weights.rbegin(), truck_weights.rend()); // ��� Ʈ��
	queue<int> bridgeTrucks; // �ٸ��� �ǳʴ� Ʈ��

	while(true)
	{
		// �ٸ����� Ʈ�� ť�� �� �� ���
		if(bridgeTrucks.size() == bridge_length)
		{
			curWeight -= bridgeTrucks.front();
			if (bridgeTrucks.front() != 0)
				passTruck++;
			bridgeTrucks.pop();
		}

		if (passTruck == truck_weights.size()) break;

		// �ٸ����� Ʈ���� �� �ö� �� �ִ� ���
		if(bridgeTrucks.size() < bridge_length)
		{
			if(!trucks.empty())
			{
				// �ٸ��� �ִ� ���Կ� �������� �ʴ� ���
				if (trucks.back() + curWeight <= weight)
				{
					bridgeTrucks.push(trucks.back());
					curWeight += trucks.back();
					trucks.pop_back();
				}
				else // �ٸ��� �ִ� ���԰� �ö��־ ���ǳʴ� ���
					bridgeTrucks.push(0);
			}
			else
				bridgeTrucks.push(0);
		}
		time++;
	}
	return time;
}

int main()
{
	//cout << solution(2, 10, { 7,4,5,6 });
	//cout << solution(100, 100, { 10 });
	//cout << solution(100, 100, { 10 });
	cout << solution(5, 5, { 2,2,2,2,1,1,1,1,1 });
}