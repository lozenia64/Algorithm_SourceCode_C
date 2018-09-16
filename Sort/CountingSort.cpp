// lozenia64
// https://blog.naver.com/ljy9378/221357120126
// Algorithm source cod for c++

void CountingSort(int *arr, int begin, int end) {
	int SortedArray[SIZE + 1], count[MAXNUM + 1], countSum[MAXNUM + 1];
	memset(count, 0, sizeof(count));
	for (int i = 1; i <= SIZE; i++) count[arr[i]]++;
	countSum[0] = count[0];
	for (int i = 1; i <= MAXNUM; i++) countSum[i] = countSum[i - 1] + count[i];
	for (int i = SIZE; i >= 1; i--) SortedArray[countSum[arr[i]]] = arr[i], countSum[arr[i]]--;
	//for (int i = 1; i <= SIZE; i++) printf("%d ", SortedArray[i]);
}

// 	CountingSort(Counting, 0, SIZE - 1);