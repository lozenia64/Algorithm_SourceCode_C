// lozenia64
// blog.naver.com/ljy9378
// Algorithm source code for c++

void RadixSort(int *arr, int begin, int end) {
	for (int i = begin; i <= end; i++) arr[i] ^= INT_MIN;
	vector<int> buf(end - begin + 1), cnt(256), idx(256);
	int *org = arr + begin, *des = &buf[0];
	for (int i = 0; i < sizeof(int); i++, swap(org, des)) {
		fill(cnt.begin(), cnt.end(), 0);
		for (int j = 0; j <= end - begin; j++) cnt[(org[j] >> (i << 3)) & 0xFF]++;
		idx[0] = 0;
		for (int i = 1; i < 256; i++) idx[i] = idx[i - 1] + cnt[i - 1];
		for (int j = 0; j <= end - begin; j++) des[idx[(org[j] >> (i << 3)) & 0xFF]++] = org[j];
	}
	for (int i = 0; i <= end - begin; i++) org[i] ^= INT_MIN;
	if (org != arr + begin) copy(buf.begin(), buf.end(), arr + begin);
}

// 	RadixSort(Radix, 0, SIZE - 1);