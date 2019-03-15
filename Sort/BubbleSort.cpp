// lozenia64
// blog.naver.com/ljy9378
// Algorithm source code for c++

void BubbleSort(int *arr, int begin, int end) {
	// i는 오른쪽 끝에서 하나씩 계속 줄어듬(최대값을 오른쪽 끝에두고 앞으로 고려하지 않음)
	for (int i = end; i > begin; i--) {
		// j는 앞에서부터 쭉 보면서 최대값을 오른쪽으로 계속 보냄
		for (int j = begin; j < i; j++) {
			// j번째 원소가 오른쪽보다 크면 오른쪽으로 보냄 (최대값을 오른쪽으로 보낸다)
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

// BubbleSort(Bubble, 0, SIZE - 1);