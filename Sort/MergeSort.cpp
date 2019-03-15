// lozenia64
// blog.naver.com/ljy9378
// Algorithm source code for c++

void MergeArray(int *arr, int *copy, int start, int end) {
	int mid = (start + end) / 2, i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		//두 원소를 비교하여 작은 원소를 copy[]의 앞에 저장.
		if (arr[i] <= arr[j]) copy[k++] = arr[i++];
		else copy[k++] = arr[j++];
	}
	//앞에서 뒤의 원소가 더 작아 앞의 원소가 남았다면 그 원소를 copy[]의 뒤에 저장.
	while (i <= mid) copy[k++] = arr[i++];
	//앞에서 앞의 원소가 더 작아 뒤의 원소가 남았다면 그 원소를 copy[]의 뒤에 저장.
	while (j <= end) copy[k++] = arr[j++];
	//copy[]를 arr[]에 복사.
	for (int i = start; i <= end; i++) arr[i] = copy[i];
}
void MergeSort(int *arr, int *copy, int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	//MergeSort를 재귀적으로 실행하여 배열의 각 원소들을 0,1개 단위까지 쪼갠다.
	MergeSort(arr, copy, start, mid);
	MergeSort(arr, copy, mid + 1, end);
	//MergeArray로 정렬.
	MergeArray(arr, copy, start, end);
}

// 	MergeSort(Merge, MergeCopy, 0, SIZE - 1);