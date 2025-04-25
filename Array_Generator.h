#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

//the function to measure the runtime of funciton

template <typename Func, typename... Args>
double measureExecutionTime(Func func, Args &&...args) {
	auto start = std::chrono::high_resolution_clock::now();

	func(std::forward<Args>(args)...);

	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	return duration.count() / 1000.0;
}

//generate an already sorted array where k is the minimum value of the largest element

vector<int> sorted(int n, int k)
{
	vector<int> a(n)
	int maxinterval = k / (n-1);
	a[0] = 0;
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] + 1 + maxinterval + rand() % 10;
	}

	return a;
}

//generate a random array where k is the minimum value of the largest element

vector<int> randomarray(int soluong, int k)
{

	vector<int> a = sorted(soluong, chantren);
	random_device rd;
	mt19937 g(rd());
	shuffle(a, a+soluong,g);
	return a;
}

//generate a nearly sorted array where k is the minimum value of the largest element

vector<int> nearlysorted(int n, int k)
{
	vector<int> a = sorted(n, k);
	for (int i = 0; i < n - 5; i += 5)
	{
		int num1 = i + rand() % 5, num2 = i + rand() % 5;
		while (num1 == num2) num2 = i + rand() % 5;
		swap(a[num1], a[num2]);
	}
	return a;
}

//generate a reversearray where k is the minimum value of the largest element

vector<int> reversesort(int n, int k)
{
	vector<int> a = sorted(n, k);
	vector<int> b(n);
	for (int i = 0; i < n; i++) b[i] = a[n - 1 - i];
	return b;
}

//check if the array has been sorted or not

bool checksorted(vector<int> a, int leftbound, int rightbound)
{

	for (int i = leftbound; i < rightbound; i++)
	{
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

