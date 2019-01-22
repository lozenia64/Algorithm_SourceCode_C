#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int n, m;
	queue<int> q;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s[0] == 'p') {
			if (s[1] == 'u') {
				scanf("%d", &m);
				q.push(m);
			}
			else {
				if (q.size() == 0) printf("-1\n");
				else {
					printf("%d\n", q.front());
					q.pop();
				}
			}
		}
		else if (s[0] == 's') printf("%d\n", q.size());
		else if (s[0] == 'e') {
			if (q.size() == 0) printf("1\n");
			else printf("0\n");
		}
		else if (s[0] == 'f') {
			if (q.size() > 0) printf("%d\n", q.front());
			else printf("-1\n");
		}
		else if (s[0] == 'b') {
			if (q.size() > 0) printf("%d\n", q.back());
			else printf("-1\n");
		}
	}
}