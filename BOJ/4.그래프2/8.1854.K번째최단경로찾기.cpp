#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
#define MAXV 1010
using namespace std;

typedef pair<int, int> P;
int V, E, k, u, v, w;
vector<P> G[MAXV];
priority_queue<P, vector<P>, greater<P>> pq;
priority_queue<int> dist[MAXV];

int main() {
	scanf("%d %d %d", &V, &E, &k);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(P(v, w));
	}

	pq.push(P(0, 1));
	dist[1].push(0);

	while (!pq.empty()) {
		int u = pq.top().second, cost = pq.top().first;
		pq.pop();

		for (auto to : G[u]) {
			int v = to.first, vcost = to.second;
			if (dist[v].size() < k) {
				dist[v].push(vcost + cost);
				pq.push(P(vcost + cost, to.first));
			}
			else if (dist[v].top() > vcost + cost) {
				dist[v].pop();
				dist[v].push(vcost + cost);
				pq.push(P(vcost + cost, to.first));
			}
		}
	}
	for (int i = 1; i <= V; i++)
		dist[i].size() == k ? printf("%d\n", dist[i].top()) : printf("-1\n");
}
