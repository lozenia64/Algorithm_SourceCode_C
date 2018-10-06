//정렬
sort(v.begin(), v.end());
	
//정렬(내림차순)
sort(v.begin(), v.end(), greater<int>());
		
//객체 정렬
class Person{
public:
    string name;
    int age;
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};
bool operator <(const Person &a, const Person &b){
    return a.age < b.age;
}

//객체 내에 오퍼레이터
class Person{
public:
    string name;
    int age;
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    bool operator <(const Person &a) const {
        return this->age < a.age;
    }
};
