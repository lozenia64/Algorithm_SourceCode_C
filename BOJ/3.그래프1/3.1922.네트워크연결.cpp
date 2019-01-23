#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct ks {
	int s, t, val;
};

vector<ks> E;
int parent[10002];
int n, m, ans;

bool cmp(ks d1, ks d2) {
	return d1.val < d2.val;
}

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

bool uni(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	parent[u] = v;
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++)	{
		ks temp;
		scanf("%d %d %d", &temp.s, &temp.t, &temp.val);
		E.push_back(temp);
	}

	sort(E.begin(), E.end(), cmp);

	for (int i = 0; i < m; i++)
		if (uni(E[i].s, E[i].t)) ans += E[i].val;

	printf("%d", ans);
}
