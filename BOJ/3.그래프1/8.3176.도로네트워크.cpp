#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, a, b, c, parent[100010][18], maxw[100010][18], minw[100010][18], visited[100010], depth[100010];
vector<pair<int,int>> G[100010];

void dfs(int v, int d) {
	visited[v] = true;
	depth[v] = d;
	for (auto to : G[v]) {
		if (!visited[to.first]) {
			parent[to.first][0] = v, minw[to.first][0] = to.second, maxw[to.first][0] = to.second;
			dfs(to.first, d + 1);
		}
	}
}
void makeParents() {
	for (int j = 1; j < 18; j++) for (int i = 1; i <= n; i++)
		parent[i][j] = parent[parent[i][j - 1]][j - 1], minw[i][j] = min(minw[i][j - 1], minw[parent[i][j - 1]][j - 1]), maxw[i][j] = max(maxw[i][j - 1], maxw[parent[i][j - 1]][j - 1]);
}
pair<int,int> lca(int x, int y) {
	int m = 987654321, M = -987654321;
	if (depth[x] > depth[y]) swap(x, y);
	for (int i = 17; i >= 0; i--)
		if (depth[y] - depth[x] >= (1 << i)) m = min(m, minw[y][i]), M = max(M, maxw[y][i]), y = parent[y][i];
	if (x == y) return{ m,M };
	for (int i = 17; i >= 0; i--)
		if (parent[x][i] != parent[y][i]) m = min({ m,minw[x][i],minw[y][i] }), M = max({ M,maxw[x][i],maxw[y][i] }), x = parent[x][i], y = parent[y][i];
	m = min({ m,minw[x][0],minw[y][0] });
	M = max({ M,maxw[x][0],maxw[y][0] });
	return {m, M};
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}

	dfs(1, 0);
	makeParents();

	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &a, &b);
		pair<int, int> ans = lca(a, b);
		printf("%d %d\n", ans.first, ans.second);
	}
}
