// lozenia64
// https://blog.naver.com/ljy9378/221357120126
// Algorithm source cod for c++

void InsertionSort(int *arr, int begin, int end) {
	//arr[0]~마지막까지 확인
	for (int i = begin + 1; i <= end; i++) {
		//i반째 원소를 v에 저장
		int j, v = arr[i];
		//i부터 앞으로 확인
		for (j = i; j > begin && arr[j - 1] > v; j--)
			arr[j] = arr[j - 1];
		if (i != j) arr[j] = v;
	}
}

// 	InsertionSort(Insertion, 0, SIZE - 1);