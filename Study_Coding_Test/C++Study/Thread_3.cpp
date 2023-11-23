// https://modoocode.com/270

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

void worker(int& counter, mutex& m)
{
	for (int i = 0; i < 10000000; i++)
	{
		// ���ؽ��� ���ڷ� �޾� �����ϰ�, �����ڿ��� ���ؽ��� lock
		// lock_guard�� �Ҹ�� �� �˾Ƽ� lock �ߴ� ���ؽ��� unlock
		lock_guard<mutex> lock(m); 
		counter += 1;
	}
}

//void worker(int& counter, mutex& m)
//{
//	for (int i = 0; i < 10000000; i++)
//	{
//		m.lock();
//		counter += 1;
//		m.unlock();
//	}
//}

int main()
{
	vector<thread> workers;
	mutex m;
	int counter = 0;

	for (int i = 0; i < 4; i++)
		workers.push_back(thread(worker, ref(counter), ref(m)));

	for (int i = 0; i < 4; i++)
		workers[i].join();

	cout << "Counter ���� �� : " << counter << endl; // 4õ��!


}