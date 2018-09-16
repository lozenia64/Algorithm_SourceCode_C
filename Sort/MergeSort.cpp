// lozenia64
// https://blog.naver.com/ljy9378/221357120126
// Algorithm source cod for c++

void MergeArray(int *arr, int *copy, int start, int end) {
	int mid = (start + end) / 2, i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) copy[k++] = arr[i++];
		else copy[k++] = arr[j++];
	}
	while (i <= mid) copy[k++] = arr[i++];
	while (j <= end) copy[k++] = arr[j++];
	for (int i = start; i <= end; i++) arr[i] = copy[i];
}
void MergeSort(int *arr, int *copy, int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	MergeSort(arr, copy, start, mid);
	MergeSort(arr, copy, mid + 1, end);
	MergeArray(arr, copy, start, end);
}

// 	MergeSort(Merge, MergeCopy, 0, SIZE - 1);