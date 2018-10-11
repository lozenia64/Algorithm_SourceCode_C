#include <tuple>
#include <string>
#include <iostream>
using namespace std;

void print(tuple<int, bool> tVal) {
    cout << get<0>(tVal) << ", " << get<1>(tVal) << endl;
}

int main() {
    //make tuple variable.
    typedef tuple<int, string, bool> OddOrEven;
 	OddOrEven myNumber1 = make_tuple(10, string("Even"), true);
    OddOrEven myNumber2 = make_tuple(7, string("Odd"), false);

    //size
    cout << "size : " << tuple_size<decltype(myNumber1)>::value << endl;
 
	//tuple의 원소를 참조하는 방법
	//tuple_elment
    tuple_element<0, decltype(myNumber1)>::type nNum = get<0>(myNumber1);
    //auto
	auto sStr = get<1>(myNumber1);
	//datatype
    bool bEven = get<2>(myNumber1);
	
	//boolalpha
    cout << nNum << ", " << sStr << ", " << boolalpha << bEven << endl;
	
    //tie() and ignore.
    int iInt;
    tie(iInt, ignore, bEven) = myNumber1;
    cout << iInt << ", " << bEven << endl;
 
    //tuple_cat function.
    auto myNums = tuple_cat(myNumber1, myNumber2);
    cout << "Value 1 : " << get<0>(myNums) << ", " << get<1>(myNums) << ", " << get<2>(myNums) << endl;
    cout << "Value 2 : " << get<3>(myNums) << ", " << get<4>(myNums) << ", " << get<5>(myNums) << endl;

    //foward_as_tuple
    print(forward_as_tuple(iInt, bEven));
}