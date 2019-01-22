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
	int n, q;
	scanf("%d %d", &n, &q);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<long long> v(n);
	vector<long long> tree(tree_size);

	for (int i = 0; i<n; i++) scanf("%lld", &v[i]);
	init(v, tree, 1, 0, n - 1);

	while (q--) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (y >= x) printf("%lld\n", sum(tree, 1, 0, n - 1, x - 1, y - 1));
		else printf("%lld\n", sum(tree, 1, 0, n - 1, y - 1, x - 1));

		long long temp = b - v[a - 1];
		v[a - 1] = b;
		update(tree, 1, 0, n - 1, a - 1, temp);
	}
}
