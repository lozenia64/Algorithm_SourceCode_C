// lozenia64
// blog.naver.com/ljy9378
// Algorithm source code for c++

void QuickSort(int *arr, int begin, int end) {
	//맨앞의 원소를 피벗으로 사용
	int pivot = begin, left = begin, right = end;
	//right가 left보다 앞에오면 종료
	while (left < right) {
		while (arr[left] <= arr[pivot] && left < end)
			left += 1;
		while (arr[right] >= arr[pivot] && right > begin)
			right -= 1;
		//right가 left와 같거나 더 앞으로 가야 끝나므로 가지않는다면 left와 right를 서로 바꾸어 계속 진행되게 한다.
		if (left < right) {
			swap(arr[left], arr[right]);
			continue;
		}
		//right가 left와 같거나 더 앞으로 간다면 right가 pivot의 올바른 위치에 도달한 것. 즉, pivot과 right를 바꿔준다.
		swap(arr[pivot], arr[right]);
		QuickSort(arr, begin, right - 1);
		QuickSort(arr, right + 1, end);
	}
}

// 	QuickSort(Quick, 0, SIZE - 1);