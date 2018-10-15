#include <iostream>
#include <vector> // for vector
#include <algorithm> // for for_each
using namespace std;
 
int main() {
    vector<int> temp = {1, 2, 3, 4, 5};
     
    //Original for loop
    for (auto it = temp.begin() ; it != temp.end() ; ++it)
        cout << *it << endl;

    //STL for_each using lambda
    for_each(temp.begin(), temp.end(), [](int i) {
        cout << i << endl;
    });
 
    //Range-Based for loop
    for (auto& i : temp)
        cout << i << endl;
}