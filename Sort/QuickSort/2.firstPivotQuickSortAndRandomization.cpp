#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#define MAXN 1000000
using namespace std;

void makeArray(int *arr) {
	for (int i = 0; i < MAXN; i++)
		arr[i] = rand();
}

void suffleArray(int *arr) {
	for (int i = 0; i < MAXN; i++)
		swap(arr[(rand()*rand()) % MAXN], arr[(rand()*rand()) % MAXN]);
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

void copyArrToANS(int *arr, int *ans) {
	for (int i = 0; i<MAXN; i++)
		ans[i] = arr[i];
}

void checkArr(int *arr, int *ans) {
	for (int i = 0; i<MAXN; i++)
		if (arr[i] != ans[i]) {
			printf("Sort ERROR!\n");
			return;
		}
}

int Arr[MAXN], ANS[MAXN];

int main() {
	clock_t start_time, end_time;

	makeArray(Arr);
	sort(Arr, Arr + MAXN);
	copyArrToANS(Arr, ANS);

	start_time = clock();
	firstPivotQuicksort(Arr, 0, MAXN - 1);
	end_time = clock();
	printf("firstPivotQuicksort\t\t:\t%lf\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
	checkArr(Arr, ANS);

	start_time = clock();
	suffleArray(Arr);
	firstPivotQuicksort(Arr, 0, MAXN - 1);
	end_time = clock();
	printf("suffleQuicksort\t\t\t:\t%lf\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
	checkArr(Arr, ANS);
}