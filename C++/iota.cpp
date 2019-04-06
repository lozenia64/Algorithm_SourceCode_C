#include <iostream>
#include <numeric> //iota
using namespace std;

void printArray(int *beginArr, int *endArr){
    for(int i=0; &beginArr[i]<endArr; i++)
        printf("%d ", beginArr[i]);
    printf("\n");
}

int main(){
    int Arr[10];

    iota(Arr, Arr+10, 0);
    printArray(Arr, Arr+10);

    iota(Arr, Arr+10, 1);
    printArray(Arr, Arr+10);

    return 0;
}