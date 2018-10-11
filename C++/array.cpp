#include <array>
#include <iostream>
using namespace std;

int main() {
    int normal[5] = { 0, 1, 2, 3, 4 };
    int* first = normal;
    cout << *first << endl;
 
    array<int, 5> data = { 0, 1, 2, 3, 4 };
    // first = data; // error
    first = data.data();
    cout << *first << endl;
 
    //size
    cout << "Size: " << data.size() << endl;
 
    //iterator 정석
    for (auto it = data.cbegin(); it != data.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
 
	//iterator 간단
	for (auto &it : data) cout << it << " ";
    cout << endl;
    
    //get an address of first element
    cout << *data.data() << endl;
 
    //C-style array and at() method access
    cout << data[1] << " " << data.at(2) << endl;
 
    //get first element
    cout << "First value: " << data.front() << endl;
 
    //get last element
    std::cout << "Last value: " << data.back() << std::endl;

	//fill method
    data.fill(6);
    for (auto elem : data) cout << elem << " ";
    cout << endl;
}