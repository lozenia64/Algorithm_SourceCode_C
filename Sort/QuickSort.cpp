// lozenia64
// https://blog.naver.com/ljy9378/221357120126
// Algorithm source cod for c++

void QuickSort(int *arr, int begin, int end) {
	int pivot = begin, left = begin, right = end;
	while (left < right) {
		while (arr[left] <= arr[pivot] && left < end)
			left += 1;
		while (arr[right] >= arr[pivot] && right > begin)
			right -= 1;
		if (left < right) {
			swap(arr[left], arr[right]);
			continue;
		}
		swap(arr[pivot], arr[right]);
		QuickSort(arr, begin, right - 1);
		QuickSort(arr, right + 1, end);
	}
}

// 	QuickSort(Quick, 0, SIZE - 1);