#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXV 10010
using namespace std;
int V, E, a, b, discover[MAXV], cut[MAXV], ans, disNum;
vector<int> G[MAXV];
int dfs(int v, bool r) {
	discover[v] = ++disNum;
	int ret = discover[v], child = 0;
	for (int w : G[v]) {
		if (!discover[w]) {
			child++;
			int df = dfs(w, 0);
			if (!r && df >= discover[v]) cut[v] = true;
			ret = min(ret, df);
		}
		else ret = min(ret, discover[w]);
	}
	if (r && child > 1) cut[v] = true;
	return ret;
}
int main() {
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= V; i++)
		if (!discover[i]) dfs(i, 1);
	for (int i = 1; i <= V; i++)
		if (cut[i]) ans++;

	printf("%d\n", ans);
	for (int i = 1; i <= V; i++) 
		if (cut[i]) printf("%d ", i);
}
