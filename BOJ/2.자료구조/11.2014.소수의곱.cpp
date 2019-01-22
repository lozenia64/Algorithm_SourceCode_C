#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

vector<long long> v;
priority_queue<long long, vector<long long>, greater<long long> > pq;
int k, n, m;

int main() {
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &m);
		v.push_back(m);
		pq.push(m);
	}

	long long head = 0;
	for (int i = 0; i < n; i++) {
		head = pq.top();
		pq.pop();

		for (int j = 0; j < k; j++) {
			pq.push(head * v[j]);
			if (head%v[j] == 0) break;
		}
	}

	printf("%d", head);
}