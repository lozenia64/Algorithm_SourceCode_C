#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> st;
	char str[35];
	int temp = 1, ans = 0;
	scanf("%s", str);

	for (int i = 0; str[i]; i++) {
		switch (str[i]) {
		case '(':
			temp *= 2, st.push('('); break;
		case '[':
			temp *= 3, st.push('['); break;
		case ')':
			if (str[i - 1] == '(') ans += temp;
			if (st.empty()) return !printf("0");
			if (st.top() == '(') st.pop();
			temp /= 2; break;
		case ']':
			if (str[i - 1] == '[') ans += temp;
			if (st.empty()) return !printf("0");
			if (st.top() == '[') st.pop();
			temp /= 3;
		}
	}
	printf("%d", st.empty() ? ans : 0);
}