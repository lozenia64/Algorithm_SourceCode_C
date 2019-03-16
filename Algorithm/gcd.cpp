
int gcd(int a, int b) {
	if (b == 0) return a;
	gcd(b, a % b);
}

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}