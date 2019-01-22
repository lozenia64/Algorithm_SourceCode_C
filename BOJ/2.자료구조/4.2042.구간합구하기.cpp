#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end) {
	if (start == end) return tree[node] = v[start];
	else return tree[node] = init(v, tree, node * 2, start, (start + end) / 2) + init(v, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<long long> v(n);
	vector<long long> tree(tree_size);

	m += k;
	for (int i = 0; i<n; i++) scanf("%lld", &v[i]);
	init(v, tree, 1, 0, n - 1);

	while (m--) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			long long b, c;
			scanf("%lld %lld", &b, &c);
			long long temp = c - v[b - 1];
			v[b - 1] = c;
			update(tree, 1, 0, n - 1, b - 1, temp);
		}
		else if (a == 2) {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(tree, 1, 0, n - 1, b - 1, c - 1));
		}
	}
}
