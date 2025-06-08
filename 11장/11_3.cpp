#include <iostream>
#include <cstring>
using namespace std;

// cin.get(char*, int)를 이용한 문자열 입력

int main() {

	int num;

	cout << "정수를 입력 : ";
	cin >> num;

	cin.ignore(1);

	char* name = new char[num];

	cout << "cin.get(char*, int) 사용하여 문자열 입력 : ";
	cin.get(name, num); // num만큼의 문자열 읽음
	if (strcmp(name, "exit") == 0) {
		cout << "프로그램을 종료" << endl;
		return 0;
	}
	else {
		cin.ignore(1);
	}

	cout << "입력된 문자열 : " << name << endl;

	delete[] name;

	return 0;
}