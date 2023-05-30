#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	// A: 낮에 올라가는 거리
	// B: 밤에 미끄러지는 거리
	// V: 나무막대의 높이
	int A, B, V;
	int days = 0;
	int curV = 0;

	cin >> A >> B >> V;

	// 정상에 올라간 후에는 달팽이가 미끄러지지 않기 때문에
	// 목표 지점은 V가 아닌, V-A이다.
	// V-A에 도달하면 다음날 A만큼 올라가 정상에 도달하기 때문
	days += (V - A) / (A - B) + 1;

	// (V-A)%(A-B) 가 0일때는 다음날 A만큼 올라 1만 더하면 되지만
	// 0이 아닐때는 정상에 도달하기에 이동거리가 A보다 조금 모잘라 하루를 추가로 더해주면 된다.
	if ((V - A) % (A - B) != 0)
		days++;

	cout << days << endl;
	return 0;
}