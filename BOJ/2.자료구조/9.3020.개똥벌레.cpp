#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, h, m;
int sum1[500010], sum2[500010];
vector<int> v, w;

int main() {
	scanf("%d %d", &n, &h);

	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		if (i % 2 == 0) v.push_back(m);
		else w.push_back(m);
	}

	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	
	int i = 0, temp = 0, cnt = 0, l = v.size();
	sum1[0] = l;
	while (i<l) {
		if (v[i] == temp) cnt++, i++;
		else if (v[i] > temp) {
			sum1[temp + 1] = sum1[temp] - cnt;
			temp++, cnt = 0;
		}
	}

	i = 0, temp = 0, cnt = 0, l = w.size();
	sum2[0] = l;
	while (i<l) {
		if (w[i] == temp) cnt++, i++;
		else if (w[i] > temp) {
			sum2[temp + 1] = sum2[temp] - cnt;
			temp++, cnt = 0;
		}
	}

	for (int i = h; i >= 1; i--) sum1[h - i +1] += sum2[i];

	sort(sum1 + 1, sum1 + h+1);

	int ans1 = sum1[1], ans2 = 1;
	for (int i = 2; i <= h; i++) {
		if (sum1[i] == ans1) ans2++;
		else return !printf("%d %d", ans1, ans2);
	}
}