#include <iostream>
using namespace std;

int n;
int tree[30][2];

void preorder(int v) {
	printf("%c", v + 64);
	if (tree[v][0] != 0) preorder(tree[v][0]);
	if (tree[v][1] != 0) preorder(tree[v][1]);
}
void inorder(int v) {
	if (tree[v][0] != 0) inorder(tree[v][0]);
	printf("%c", v + 64);
	if (tree[v][1] != 0) inorder(tree[v][1]);
}
void postorder(int v) {
	if (tree[v][0] != 0) postorder(tree[v][0]);
	if (tree[v][1] != 0) postorder(tree[v][1]);
	printf("%c", v + 64);
}


int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		char c, d, e;
		cin >> c >> d >> e;
		if (d == '.') d = 64;
		if (e == '.') e = 64;
		tree[c - 64][0] = d - 64, tree[c - 64][1] = e - 64;
	}

	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	postorder(1);
}