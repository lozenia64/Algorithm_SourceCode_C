// lozenia64
// https://blog.naver.com/ljy9378/221357120126
// Algorithm source cod for c++

void BubbleSort(int *arr, int begin, int end) {
	for (int i = end; i > begin; i--) {
		for (int j = begin; j < i; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

// BubbleSort(Bubble, 0, SIZE - 1);