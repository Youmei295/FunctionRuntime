#pragma once
#include <iostream>
#include <vector>
using namespace std;

//heap sort:

void heapify(vector<int> &a, int n, int i)
{
	int child = 2 * i + 1;
	if (child >= n) { return; }
	if (a[child] < a[child + 1] && child + 1 < n) child++;
	if (a[i] >= a[child])  return;
	else swap(a[i], a[child]);
	heapify(a, n, child);
}

void buildheap(vector<int> &a, int n)
{
	int lastparent = n / 2 - 1;
	for (int i = lastparent; i >= 0; i--)
	{
		heapify(a, n, i);
	}
}

void heapsort(vector<int> &a, int n)
{
	buildheap(a, n);
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);

	}
}


//countingsort:

void countingsort(vector<int> &a, int leftbound, int rightbound)
{
	int soluong = rightbound - leftbound + 1;
	vector<int> output(soluong);
	int maxx = a[leftbound];
	for (int i = leftbound + 1; i <= rightbound; i++)
	{
		if (a[i] > maxx) { maxx = a[i]; }
	}
	cout << maxx << " ";
	vector<int> b(maxx+1);
	for (int i = 0; i < maxx + 1; i++)
	{
		b[i] = 0;
	}
	for (int i = leftbound; i < rightbound + 1; i++)
	{
		b[a[i]]++;
	}
	for (int i = leftbound+1; i < maxx + 1; i++)
	{
		b[i] += b[i - 1];
	}
	for (int i = rightbound; i >= leftbound; i--)
	{
		output[--b[a[i]]] = a[i];
	}
	
	for (int i = leftbound; i <= rightbound; i++) a[i] = output[i];
}




