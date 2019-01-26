#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, a, b, parent[100010][18], visited[100010], depth[100010];
vector<int> G[100010];

void dfs(int v, int d) {
	visited[v] = true;
	depth[v] = d;
	for (int to : G[v]) {
		if (!visited[to]) {
			parent[to][0] = v;
			dfs(to, d + 1);
		}
	}
}
void makeParents() {
	for (int j = 1; j < 18; j++) for (int i = 1; i <= n; i++) parent[i][j] = parent[parent[i][j - 1]][j - 1];
}
int lca(int x, int y) {
	if (depth[x] > depth[y]) swap(x, y);
	for (int i = 17; i >= 0; i--)
		if (depth[y] - depth[x] >= (1 << i)) y = parent[y][i];
	if (x == y) return x;
	for (int i = 17; i >= 0; i--)
		if (parent[x][i] != parent[y][i]) x = parent[x][i], y = parent[y][i];
	return parent[x][0];
}
