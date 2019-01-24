#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXV 510
#define INF 987654321
using namespace std;

typedef pair<int, int> P;
int V, E, u, v, w, dist[20010], cost[20010], inq[20010], cycle[20010];
vector<P> G[20010];
queue<int> q;

int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(P(v, w));
	}

	for (int s = 1; s <= V; s++) {
		fill(dist, dist + MAXV, INF);
		fill(inq, inq + MAXV, 0);
		fill(cycle, cycle + MAXV, 0);
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
						if (cycle[v] >= V) return !printf("-1\n");
						q.push(v); inq[v] = true;
					}
				}
			}
		}

		for (int i = 1; i <= V; i++) {
			if (i == s) printf("0 ");
			else {
				if (dist[i] >= INF) printf("0 ");
				else printf("%d ", dist[i]);
			}
		}
		printf("\n");
	}
}
