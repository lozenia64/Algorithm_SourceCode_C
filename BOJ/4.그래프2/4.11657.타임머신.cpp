#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXV 510
#define INF 987654321
using namespace std;

typedef pair<int, int> P;
int V, E, u, v, w, dist[MAXV], inq[MAXV], cycle[MAXV];
vector<P> G[MAXV];
queue<int> q;

int SPFA(int s) {
	dist[s] = 0, q.push(s), inq[s] = 1, cycle[s]++;
	while (!q.empty()) {
		int u = q.front();
		q.pop(); inq[u] = 0;
		for (auto to : G[u]) {
			int v = to.first, w = to.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				if (!inq[v]) {
					cycle[v]++;
					if (cycle[v] >= V) return -1;
					q.push(v); inq[v] = true;
				}
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(P(v, w));
	}
	fill(dist, dist + MAXV, INF);

	if (SPFA(1) == -1) return !printf("-1\n");
	for (int i = 2; i <= V; i++)
		dist[i] >= INF ? printf("-1\n") : printf("%d\n", dist[i]);
}
