#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m, a, b, ans=0;
bool visited[100010];
vector<int> OG[100010], IG[100010];

void dfs(vector<int> G[], int v) {
	visited[v] = true;
	for (int to = 0; to < G[v].size(); to++)
		if (!visited[G[v][to]]) dfs(G, G[v][to]);
}

int main() {
	scanf("%d %d", &n, &m);

	while (m--) {
		scanf("%d %d", &a, &b);
		OG[b].push_back(a);
		IG[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		dfs(OG, i);
		dfs(IG, i);

		bool flag = true;
		for (int j = 1; j <= n; j++)
			if (!visited[j]) flag = false;
		if (flag) ans++;
	}

	printf("%d", ans);
}
