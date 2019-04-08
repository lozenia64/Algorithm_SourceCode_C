#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#define MAXN 1000000
using namespace std;

void makeArray(int *arr) {
	for (int i = 0; i<MAXN; i++)
		arr[i] = rand();
}

void firstPivotQuicksort(int *arr, int begin, int end) {
	if (end <= begin) return;
	int pivot = begin, left = begin, right = end + 1;

	while (left < right) {
		do { left++; } while (arr[pivot] > arr[left] && left <= end);
		do { right--; } while (arr[pivot] < arr[right] && right >= begin + 1);
		if (left < right) swap(arr[left], arr[right]);
	}
	swap(arr[begin], arr[right]);
	firstPivotQuicksort(arr, begin, right - 1);
	firstPivotQuicksort(arr, right + 1, end);
}

int Arr[MAXN];

int main() {
	clock_t start_time, end_time;

	makeArray(Arr);

	start_time = clock();
	firstPivotQuicksort(Arr, 0, MAXN - 1);
	end_time = clock();
	printf("NON-Worst : firstPivotQuicksort\t\t:\t%lf\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

	start_time = clock();
	firstPivotQuicksort(Arr, 0, MAXN - 1);
	end_time = clock();
	printf("Worst : firstPivotQuicksort\t\t:\t%lf\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
}