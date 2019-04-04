#include <stdio.h>
#include <process.h>

void printString(void *arr) {
	char *ptr = (char*)arr;
	for (int i = 0; ptr[i] != '\0'; i++)
		printf("%c", ptr[i]);
	printf("\n");
}
void printNumber(void *arr) {
	int *ptr = (int*)arr;
	for (int i = 0; i < 10; i++)
		printf("%d", ptr[i]);
	printf("\n");
}

int main() {
	char String[20] = "Hello World!";
	int Number[10];

	for (int i = 0; i < 10; i++)
		Number[i] = i;

	_beginthread(printString, 0, (void*)String);
	_beginthread(printNumber, 0, (void*)Number);

	while (true);

	return 0;
}