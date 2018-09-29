// lozenia64
// https://blog.naver.com/ljy9378/221357120126
// Algorithm source cod for c++

void SelectionSort(int *arr, int begin, int end) {
	//처음부터 쭉 반복
	for (int i = begin; i < end; i++) {
		int tmp = i;
		for (int j = i + 1; j <= end; j++)
			if (arr[tmp] > arr[j]) tmp = j;
		if (tmp != i) swap(arr[i], arr[tmp]);
	}
}
// SelectionSort(Selection, 0, SIZE - 1);