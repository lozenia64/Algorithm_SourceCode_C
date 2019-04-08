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

void copyArrToANS(int *arr, int *ans) {
	for (int i = 0; i < MAXN; i++)
		ans[i] = arr[i];
}

void checkArr(int *arr, int *ans) {
	for (int i = 0; i < MAXN; i++)
		if (arr[i] != ans[i]) {
			printf("Sort ERROR!\n");
			return;
		}
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

void randomPivotQuicksort(int *arr, int begin, int end) {
	if (end <= begin) return;
	int pivot = (rand() % (end - begin + 1)) + begin, left = begin, right = end + 1;

	swap(arr[begin], arr[pivot]);
	while (left < right) {
		do { left++; } while (arr[begin] > arr[left] && left <= end);
		do { right--; } while (arr[begin] < arr[right] && right >= begin + 1);
		if (left < right) swap(arr[left], arr[right]);
	}
	swap(arr[begin], arr[right]);
	randomPivotQuicksort(arr, begin, right - 1);
	randomPivotQuicksort(arr, right + 1, end);
}

int findMedianIndex(int *arr, int a, int b, int c) {
	int median = (arr[a] + arr[b] + arr[c]) - max({ arr[a], arr[b], arr[c] }) - min({ arr[a], arr[b], arr[c] });
	return median == arr[a] ? a : median == arr[b] ? b : c;
}

void threePivotQuicksort(int *arr, int begin, int end) {
	if (end <= begin) return;
	int pivot = findMedianIndex(arr, begin, end, (begin + end) / 2), left = begin, right = end + 1;

	swap(arr[begin], arr[pivot]);
	while (left < right) {
		do { left++; } while (arr[begin] > arr[left] && left <= end);
		do { right--; } while (arr[begin] < arr[right] && right >= begin + 1);
		if (left < right) swap(arr[left], arr[right]);
	}
	swap(arr[begin], arr[right]);
	threePivotQuicksort(arr, begin, right - 1);
	threePivotQuicksort(arr, right + 1, end);
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

	start_time = clock();
	randomPivotQuicksort(Arr, 0, MAXN - 1);
	end_time = clock();
	printf("randomPivotQuicksort\t\t:\t%lf\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
	checkArr(Arr, ANS);

	start_time = clock();
	threePivotQuicksort(Arr, 0, MAXN - 1);
	end_time = clock();
	printf("threePivotQuicksort\t\t:\t%lf\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
	checkArr(Arr, ANS);
}