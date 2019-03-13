// lozenia64
// blog.naver.com/ljy9378
// Algorithm source cod for c++

void CountingSort(int *arr, int begin, int end) {
	// 배열 count[], countSum[], SortedArray[] 선언
	int SortedArray[SIZE + 1], count[MAXNUM + 1], countSum[MAXNUM + 1];
	memset(count, 0, sizeof(count));
	// count 배열에서 arr[]의 각 원소의 숫자를 세어준다.
	for (int i = 1; i <= SIZE; i++) count[arr[i]]++;
	countSum[0] = count[0];
	// countSum[]에 누적합을 저장한다.
	for (int i = 1; i <= MAXNUM; i++) countSum[i] = countSum[i - 1] + count[i];
	//arr[]의 마지막 원소부터 countSum을 통해 정렬된 자리를 찾아준다.
	for (int i = SIZE; i >= 1; i--) SortedArray[countSum[arr[i]]] = arr[i], countSum[arr[i]]--;
	//for (int i = 1; i <= SIZE; i++) printf("%d ", SortedArray[i]);
}

// 	CountingSort(Counting, 0, SIZE - 1);