#include <iostream>
#include <algorithm>
using namespace std;

void upperToLower(char* _str, int _strSize) {
	printf("upper to lower : ");
	for (int i = 0; i < _strSize; i++)
		printf("%c", _str[i] + 32);
	printf("\n");
}

void lowerToUpper(char* _str, int _strSize) {
	printf("lower to upper : ");
	for (int i = 0; i < _strSize; i++)
		printf("%c", _str[i] - 32);
	printf("\n");
}

void upperToLowerBit(char* _str, int _strSize) {
	printf("upper to lower : ");
	int uToL = 1 << 5;
	for (int i = 0; i < _strSize; i++)
		printf("%c", _str[i] ^ uToL);
	printf("\n");
}

void lowerToUpperBit(char* _str, int _strSize) {
	printf("lower to upper : ");
	int LToU = 1 << 5;
	for (int i = 0; i < _strSize; i++)
		printf("%c", _str[i] ^ LToU);
	printf("\n");
}

void printString(char* str, int strSize) {
	for (int i = 0; i < strSize; i++)
		printf("%c", str[i]);
}

int main() {
	char STR[] = "STRING", str[] = "string";
	upperToLowerBit(STR, sizeof(STR));
	lowerToUpperBit(str, sizeof(str));

	char string[] = "aEbDcCdBeA";
	int stringSize = sizeof(string) / sizeof(char);
	sort(string, string + stringSize - 1);
	printString(string, stringSize);
}