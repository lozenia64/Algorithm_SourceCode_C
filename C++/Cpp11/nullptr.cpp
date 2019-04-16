#include <iostream>
using namespace std;

int Integer, *Pointer;

void print(int ptr) {
	Integer = ptr;
	cout << "integer : " << ptr << endl;
}

void print(int* ptr) {
	Pointer = ptr;
	cout << "pointer : " << ptr << endl;
}

int main() {
	Pointer = &Integer;
	print(10);
	print(NULL);
	print(nullptr);
}
