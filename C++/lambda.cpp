#include <iostream>
using namespace std;
 
int main() {
    int a = 0, b = 1, c = 2;
	//capture(캡처)
	//[=] : 모든 변수를 call by value
	//[&] : 모든 변수를 call by reference
	//[a] : 변수 a만 call by value(변수 하나만 call by value시에는 = 사용하지 않음)
	//[&a] : 변수 a만 call by reference
	//[&, a] : 변수 a만 call by value, 나머지 모든 변수를 call by reference
	//[=, &a] : 변수 a만 call by reference, 나머지 모든 변수를 call by value
    [&a, b]() {
        cout << a << ", " << b << endl;
        // cout << c << endl; //변수 c는 캡처하지 않았기 때문에 사용할 수 없다.
    }();
	
	[=]() {
        //a = 3; //변수 a는 call by value로 캡처했기 때문에 값을 변경할 수 없다.
    }();
	
	//mutable 사용 시 value로 캡처한 값도 변경 가능
	[=]() mutable {
        a = 3;
        cout << a << endl;
    }();
    cout << a << endl;
	
	// -> type으로 return 타입을 지정
	a = [=]() mutable throw() -> int {
        return 1000;
    }();
	cout << a << endl;
}