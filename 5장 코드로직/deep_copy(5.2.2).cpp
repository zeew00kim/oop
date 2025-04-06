#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 숙쁠쁠 5-2 실습 2, 3 번째 문제 : 깊은 복사 생성자 만들기
class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);
	Person(const Person& copified);
	~Person();
	void changeName(const char* name);
	void show() {
		cout << id << ", " << name << endl;
	}
};

Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
	cout << "origin obj name : " << this->name << endl;
}

Person::Person(const Person& copified) {
	this->id = copified.id;
	int len = strlen(copified.name);
	this->name = new char[len + 1];
	strcpy(this->name, copified.name);
	cout << "copified obj name : " << this->name << endl;
}

Person::~Person() {
	if (name != NULL) {
		delete[] name;
	}
}

// 새로 변경할 문자열 길이가 기존 문자열 길이보다 길 경우
// 원래는 그냥 return 해버렸는데 이걸 아래와 같이 수정함
void Person::changeName(const char* name) {
	
	if(strlen(name) > strlen(this->name)) {
		delete[] this->name;
		int len = strlen(name);
		this->name = new char[len + 1];
	}
	strcpy(this->name, name);
}

void changeObj(Person& changed) {
	changed.changeName("zaewan");
}

Person female() {
	Person dragon(2022, "dragonJin");
	return dragon;
}

int main() {

	Person man1(2022, "zeew00");
	Person man2(man1);

	cout << "[ after creation of man2 ]\n";

	man1.show();
	man2.show();
	changeObj(man2);
	Person girl(female());

	cout << "[ after renaming of man2 & add female ]\n";

	man1.show();
	man2.show();
	girl.show();

	return 0;
}