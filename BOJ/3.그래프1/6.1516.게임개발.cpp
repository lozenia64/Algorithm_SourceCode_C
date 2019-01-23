#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std;

int n, indegree[502], time1[502], time2[502];
vector<int> G[502];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &time1[i]);

		while (1) {
			int a;
			scanf("%d", &a);
			if (a == -1) break;

			G[a].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;

	for (int i = 1; i < n; i++)
		if (indegree[i] == 0) q.push(i);

	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int now = q.front();
			q.pop();
			indegree[now]--;
			for (int next : G[now]) {
				indegree[next]--;
				if (indegree[next] == 0) q.push(next);
				int temp = time1[now] + time2[now];
				if (temp > time2[next]) time2[next] = temp;
			}
		}
	}

	for (int i = 1; i <= n; i++) printf("%d\n", time1[i] + time2[i]);
}
