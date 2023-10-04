#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>

#define MAX 256
#define SIZE 10

using namespace std;

int heap[MAX];
int heapCnt = 0;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Push(int data)
{
	heap[++heapCnt] = data; // 인덱스는 1부터 시작

	int child = heapCnt;
	int parent = child / 2;
	while(child > 1 && heap[parent] < heap[child])
	{
		Swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

int Pop()
{
	int result = heap[1];

	Swap(&heap[1], &heap[heapCnt]);
	heapCnt--;

	int parent = 1;
	int child = parent * 2;
	if(child + 1 <= heapCnt)
		child = (heap[child] > heap[child + 1]) ? child : child + 1;

	while(child <= heapCnt && heap[parent] < heap[child])
	{
		Swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= heapCnt)
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int arr[SIZE];

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % 50 + 1;

	for (int i = 0; i < SIZE; i++)
		Push(arr[i]);

	for (int i = 0; i < SIZE; i++)
		cout << Pop() << ' ';

	cout << endl;

	return 0;
}