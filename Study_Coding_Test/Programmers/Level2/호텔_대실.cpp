#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ChangeTimeToMinutes(string time)
{
	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3, 2));

	return (h * 60) + m;
}

int solution(vector<vector<string>> book_time) {
	vector<pair<int, int>> room;
	for(int i = 0; i < book_time.size(); i++)
		room.emplace_back(ChangeTimeToMinutes(book_time[i][0]), ChangeTimeToMinutes(book_time[i][1]) + 10);

	sort(room.begin(), room.end());

	int roomCnt = 0;
	vector<pair<int, int>> useRooms;
	for (int i = 0; i < room.size(); i++)
	{
		vector<pair<int, int>> temp;
		for(int j = 0; j < useRooms.size(); j++) // �� ���� �ð����� ������� ���� ��ġ���� �˻�
		{
			// ��� �ð��� �������ٸ�, �� ���� �迭�� �߰�
			if (room[i].first < useRooms[j].second)
				temp.push_back(useRooms[j]);
		}

		useRooms = temp;
		useRooms.push_back(room[i]); // ���� ���� ��� �뿡 �߰�
		roomCnt = max(roomCnt, (int)useRooms.size());
	}

	return roomCnt;
}

int main()
{
	vector<vector<string>> book_time = { {"15:00", "17:00"},{"16:40", "18:20"},{"14:20", "15:20"},{"14:10", "19:20"},{"18:20", "21:20" } };

	cout << solution(book_time);
}