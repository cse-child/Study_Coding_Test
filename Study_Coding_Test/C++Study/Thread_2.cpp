#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void worker(int& counter)
{
	for (int i = 0; i < 10000000; i++)
		counter += 1;
}

int main()
{
	vector<thread> workers;
	int counter = 0;

	for (int i = 0; i < 4; i++)
		workers.push_back(thread(worker, ref(counter)));

	for (int i = 0; i < 4; i++)
		workers[i].join();

	cout << "Counter 최종 값 : " << counter << endl; // 4천만?


}