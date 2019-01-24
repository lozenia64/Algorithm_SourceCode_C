// 내 코드 아님. 짧길래 줏어옴.

#include <cstdio>
#define INF 987654321
using namespace std;

int n, m, path[6001][3], dist[501];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) dist[i] = INF;
	for (int i = 1; i <= m; i++) scanf("%d %d %d", &path[i][0], &path[i][1], &path[i][2]);

	dist[1] = 0;
	for (int i = 1; i<n; i++) for (int j = 1; j <= m; j++) 
			if (dist[path[j][0]] != INF && dist[path[j][1]] > dist[path[j][0]] + path[j][2]) dist[path[j][1]] = dist[path[j][0]] + path[j][2];

	for (int j = 1; j <= m; j++) 
		if (dist[path[j][0]] != INF && dist[path[j][1]] > dist[path[j][0]] + path[j][2]) return !printf("-1\n");
	
	for (int i = 2; i <= n; i++)
		dist[i] != INF ? printf("%d\n", dist[i]) : printf("-1\n");
}
