#include <iostream>
#include <set>
#include <random>
using namespace std;

set<int> binary_search_tree;

int main(){
    for(int i=0; i<10; i++)
        binary_search_tree.insert(rand());

    set<int>::iterator iter;
    for (iter = binary_search_tree.begin(); iter != binary_search_tree.end(); ++iter){
        printf("%d ", *iter);
    }
    printf("\n");
    
    for(auto i : binary_search_tree)
        printf("%d ", i);
    printf("\n");

    return 0;
}