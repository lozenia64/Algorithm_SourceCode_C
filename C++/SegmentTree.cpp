#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// �迭 v�� ����Ͽ� tree ����. 
long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end) {
	if (start == end) return tree[node] = v[start];
	else return tree[node] = init(v, tree, node * 2, start, (start + end) / 2) + init(v, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
// index�� diff��ŭ ����. 
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
// left���� right ������ �������� return 
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
