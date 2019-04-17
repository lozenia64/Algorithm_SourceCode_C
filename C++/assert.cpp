#include <iostream>
#include <cassert>
#define ASSERT(expr, ...) if(!(expr)) _asm { int 3 }
using namespace std;

double divide(int _dividend, int _divisor) {
	assert(_divisor != 0);
	ASSERT(_divisor != 0, "제수는 0이 될 수 없습니다");
	return (double)_dividend / (double)_divisor;
}

int main() {
	int dividend, divisor;

	while (true) {
		cin >> dividend >> divisor;
		cout << divide(dividend, divisor) << endl << endl;
	}
}
