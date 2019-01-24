#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXV 100010
using namespace std;

typedef pair<int, int> P;
int V, E, a, b, disNum, discover[MAXV], cut[MAXV];
vector<int> G[MAXV];
vector<P> cutEdge;

int dfs(int v, int parent) {
	discover[v] = ++disNum;
	int ret = discover[v], child = 0;
	for (int to : G[v]) {
		if (to == parent) continue;
		if (!discover[to]) {
			int df = dfs(to, v);
			if (df > discover[v]) cutEdge.push_back({ min(v,to),max(v,to) });
			ret = min(ret, df);
		}
		else ret = min(ret, discover[to]);
	}
	return ret;
}
int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= V; i++)
		if (!discover[i]) dfs(i, 0);

	sort(cutEdge.begin(), cutEdge.end());

	printf("%d\n", cutEdge.size());
	for (auto i : cutEdge)
		printf("%d %d\n", i.first, i.second);
}
