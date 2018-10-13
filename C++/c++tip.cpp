//c++ TIP
//c,c++의 모든 헤더파일을 포함하는 헤더
#include <bits/stdc++.h>
using namespace std;

struct LUCKY {
    int a, b;
    string s;
};

int main() {
    {
		//min,max 함수는 매개변수를 2개까지 받지만, 중괄호를 통해 3개 이상의 변수를 넣어줄 수 있다.
        int a = 2, b = 1, c = 6, d = 4;
        printf("%d %d\n", min({ a,b,c,d }), max({ a,b,c,d }));

		//배열의 최솟값,최댓값
        int p[] = { 5,3,2,4 };
        printf("%d %d\n", *min_element(p, p + 4), *max_element(p, p + 4));

		//벡터의 최솟값,최댓값
        vector <int> v = { 5,3,2,4 };
        printf("%d %d\n", *min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()));
    } 
	{
		//문자열 출력 후 개행
        puts("");
		
		//함수가 중괄호로 나누어져 있다면 같은 변수이름을 사용해도 상관없다.
        LUCKY a = { 1, 10, "123" };
        cout << a.a << "\n" << a.b << "\n" << a.s << "\n\n";
        LUCKY b = { 5, 5, "321" };
        LUCKY c = { 3, 20, "1234" };
        vector <LUCKY> v = { a,b,c };

		//굳이 오퍼레이터를 따로 선언하지 않고 sort에 바로 넣을 수 있다. (LUCKY 구조체를 a 기준으로 정렬)
		//[]() 형태는 c++의 람다 함수 형태이다.
        sort(v.begin(), v.end(), [&](LUCKY &p, LUCKY &q) {
            return p.a < q.a;
        });

		//&x는 벡터 v의 원소를 순서대로 참조한다.
        for (auto &x : v) cout << x.a << " " << x.b << " " << x.s << "\n";

		//int -> string
        double pi = 3.141592;
        string s = to_string(pi);
        cout << "\n" << s << "\n";
    } 
	{
        puts("");
		//키 값을 기준으로 정렬되는 map
        map <string, int> A;
		//정렬되지 않는 맵 정렬되지 않는대신 더 빠르다
        unordered_map <string, int> B;
        A["cba"] = B["cba"] = 1;
        A["pqr"] = B["pqr"] = 2;
        A["abcd"] = B["abcd"] = 3;
		//이터레이터를 사용하지 않아도 map의 원소 참조 가능
        for (auto &x : A) printf("%s : %d\n", x.first.c_str(), x.second);
        puts("");
        for (auto &x : B) printf("%s : %d\n", x.first.c_str(), x.second);
    }
}
