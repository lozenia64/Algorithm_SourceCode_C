#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, a, b;
bool visited[100010];
vector<int> G[100010];

void dfs(int v) {
	visited[v] = true;
	for (int to = 0; to < G[v].size(); to++)
		if (!visited[G[v][to]]) dfs(G[v][to]);
	printf("%d\n", v);
}

int main() {
	scanf("%d %d", &n, &m);

	while (m--) {
		scanf("%d %d", &a, &b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) if(!visited[i]) dfs(i);
}
