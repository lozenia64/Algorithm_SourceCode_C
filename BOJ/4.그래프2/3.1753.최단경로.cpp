#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
#define MAXV 20010
using namespace std;

typedef pair<int, int> P;
int V, E, k, u, v, w, dist[MAXV];
vector<P> G[MAXV];
priority_queue<P, vector<P>, greater<>> pq;

int main() {
	memset(dist, -1, sizeof(dist));
	scanf("%d %d %d", &V, &E, &k);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(P(v, w));
	}

	pq.push(P(0, k));
	while (!pq.empty()) {
		int u = pq.top().second, cost = pq.top().first;
		pq.pop();
		if (dist[u] != -1) continue;
		dist[u] = cost;
		for (auto to : G[u]) {
			int v = to.first, vcost = to.second + cost;
			if (dist[v] != -1) continue;
			pq.push(P(vcost, v));
		}
	}
	for (int i = 1; i <= V; i++)
		dist[i] == -1 ? printf("INF\n") : printf("%d\n", dist[i]);
}
