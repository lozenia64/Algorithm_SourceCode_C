// lozenia64
// blog.naver.com/ljy9378
// Algorithm source code for c++

void Heapify(int *arr, int index, int size) {
	for (int ch = (index << 1) | 1; ch < size; index = ch, ch = ch << 1 | 1) {
		if (ch + 1 < size && arr[ch + 1] > arr[ch]) ++ch;
		if (arr[ch] <= arr[index]) return;
		swap(arr[ch], arr[index]);
	}
}
void HeapSort(int *arr, int begin, int end) {
	int *base = arr + begin, size = end - begin + 1;
	for (int i = size / 2 - 1; i >= 0; i--) Heapify(base, i, size);
	while (--size >= 1) {
		swap(base[0], base[size]);
		Heapify(base, 0, size);
	}
}

// 	HeapSort(Heap, 0, SIZE - 1);