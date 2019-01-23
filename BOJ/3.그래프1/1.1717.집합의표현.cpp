#include <iostream>
using namespace std;

int find(int parent[], int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent, parent[x]);
}

void uni(int parent[], int x, int y) {
	x = find(parent, x), y = find(parent, y);
	parent[x] = y;
}

int main() {
	int n, m, a, b, c;
	int parent[1000001];

	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) parent[i] = i;

	while (m--) {
		scanf("%d %d %d", &c, &a, &b);

		if (c == 0) uni(parent, a, b);
		else if (c == 1) {
			if (find(parent, a) == find(parent, b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}
