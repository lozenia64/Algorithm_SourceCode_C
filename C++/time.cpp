#include <ctime>

int main() {
	clock_t t;
	t = clock();
	
    //시간을 측정할 함수

	printf("%lf\n", (double)(clock() - t) / CLOCKS_PER_SEC);
}