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
		// 뮤텍스를 인자로 받아 생성하고, 생성자에서 뮤텍스를 lock
		// lock_guard가 소멸될 때 알아서 lock 했던 뮤텍스를 unlock
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

	cout << "Counter 최종 값 : " << counter << endl; // 4천만!


}