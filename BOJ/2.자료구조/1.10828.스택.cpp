#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, m;
	vector<int> v;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s[0] == 'p') {
			if (s[1] == 'u') {
				scanf("%d", &m);
				v.push_back(m);
			}
			else {
				if (v.size() == 0) printf("-1\n");
				else {
					printf("%d\n", v.back());
					v.pop_back();
				}
			}
		}
		else if (s[0] == 't') {
			if(v.size() > 0) printf("%d\n", v.back());
			else printf("-1\n");
		}
		else if (s[0] == 's') printf("%d\n", v.size());
		else if (s[0] == 'e') {
			if(v.size() == 0) printf("1\n");
			else printf("0\n");
		}
	}
}