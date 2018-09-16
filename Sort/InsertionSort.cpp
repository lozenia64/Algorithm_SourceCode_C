// lozenia64
// https://blog.naver.com/ljy9378/221357120126
// Algorithm source cod for c++

void InsertionSort(int *arr, int begin, int end) {
	for (int i = begin + 1; i <= end; i++) {
		int j, v = arr[i];
		for (j = i; j > begin && arr[j - 1] > v; j--)
			arr[j] = arr[j - 1];
		if (i != j) arr[j] = v;
	}
}

// 	InsertionSort(Insertion, 0, SIZE - 1);