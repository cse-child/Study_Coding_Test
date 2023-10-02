#include <iostream>
#include <vector>

using namespace  std;

void PrintArr(const vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void BubbleSort(vector<int> arr)
{
	for(int i = 0; i < arr.size()-1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			// swap
			if(arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	PrintArr(arr);
}

void SelectSort(vector<int> arr)
{
	for(int i = 0; i < arr.size()-1; i++)
	{
		int maxPos = i;
		for(int j = i+1; j < arr.size(); j++)
		{
			if (arr[maxPos] > arr[j])
				maxPos = j;
		}
		swap(arr[maxPos], arr[i]);
	}
	PrintArr(arr);
}

void InsertionSort(vector<int> arr)
{
	for(int i = 1; i < arr.size(); i++)
	{
		int temp = arr[i];
		int j;
		for(j = i-1; j >= 0; j--)
		{
			if (temp >= arr[j]) break;

			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
	PrintArr(arr);
}

void QuickSort(vector<int>& arr, int start, int end)
{
	if (start >= end)
		return;

	int pivot = start;
	int i = pivot + 1; // 왼쪽 출발
	int j = end; // 오른쪽 출발

	while(i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;

		if (i > j) // 엇갈렸을 때
			swap(arr[j], arr[pivot]);
		else
			swap(arr[i], arr[j]);
	}

	// 분할 정복
	QuickSort(arr, start, j - 1);
	QuickSort(arr, j + 1, end);
}

vector<int> m = { 4,1,2,3,9,7,8,6,10,5 };
vector<int> m2(m.size());

void Merge(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while(i <= mid && j <= right)
	{
		if (m[i] <= m[j])
			m2[k++] = m[i++];
		else
			m2[k++] = m[j++];
	}

	int temp;
	if (i > mid)
		temp = j;
	else
		temp = i;

	while(k <= right)
		m2[k++] = m[temp++];

	for (int i = left; i <= right; i++)
		m[i] = m2[i];
}

void Partition(int left, int right)
{
	int mid;

	if(left < right)
	{
		mid = (left + right) / 2;
		Partition(left, mid);
		Partition(mid + 1, right);
		Merge(left, right);
	}
}

int main()
{
	vector<int> arr = { 3,5,1,4,2 };
	cout << "Original Arr : ";
	PrintArr(arr);
	cout << endl;

	cout << "<< Bubble Sort >>" << endl;
	BubbleSort(arr);
	cout << endl << endl;

	cout << "<< Select Sort >>" << endl;
	SelectSort(arr);
	cout << endl << endl;

	cout << "<< Insertion Sort >>" << endl;
	InsertionSort(arr);
	cout << endl << "-----------------------" <<endl;

	vector<int> q = { 4,1,2,3,9,7,8,6,10,5 };
	cout << "Original Arr : ";
	PrintArr(q);
	cout << endl;

	cout << "<< Quick Sort >>" << endl;
	QuickSort(q, 0, q.size()-1);
	PrintArr(q);
	cout << endl << "-----------------------" << endl;

	cout << "Original Arr : ";
	PrintArr(m);
	cout << endl;

	cout << "<< Merge Sort >>" << endl;
	Partition(0, m.size() - 1);
	PrintArr(m);
	cout << endl << "-----------------------" << endl;

	return 0;
}