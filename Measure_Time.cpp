#include <iostream>
#include "Array_Generator.h"
#include "Sorting_Algorithm.h"
#include <vector>
using namespace std;



int main()
{   
	srand(time(NULL));
	int n;
	cin >> n;
	n *= 1000000;
	vector<int> arr1 = randomarray(n, 1500000000), arr2 = nearlysorted(n, 1500000000), arr3 = reversesort(n, 1500000000), arr4 = sorted(n, 1500000000);
	double time1 = measureExecutionTime(heapsort,arr1,n);
	if (checksorted(arr1, 0, n - 1)) cout << "1: " << time1 << endl;
	delete[] arr1;
	double time2 = measureExecutionTime(heapsort,arr2,n);
	if (checksorted(arr2, 0, n - 1)) cout << "2: " << time2 << endl;
	delete[] arr2;
	double time3 = measureExecutionTime(heapsort, arr3, n);
	if (checksorted(arr3, 0, n - 1)) cout << "3: " << time3 << endl;
	delete[] arr3;
	double time4 = measureExecutionTime(heapsort, arr4, n);
	if (checksorted(arr4, 0, n - 1)) cout << "4: " << time4 << endl;
	delete[] arr4;
}








