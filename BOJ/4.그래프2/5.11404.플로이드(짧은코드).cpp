// 내 코드 아님. 짧길래 줏어옴.

#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m, a, b, c, dist[101][101];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
			i == j ? dist[i][j] = 0 : dist[i][j] = INF;

	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		if (dist[i][j]> dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] == INF ? printf("0 ") : printf("%d ", dist[i][j]);
		printf("\n");
	}
}
