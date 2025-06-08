#include <iostream>
using namespace std;

void get1() {
	cout << "cin.get() 사용하여 enter까지 입력 : ";
	int ch; // EOF(-1)과 비교 위해 정수형 선언
	while ((ch = cin.get()) != EOF) {
		cout.put(ch);
		if (ch == '\n') {
			break;
		}
	}
}

void get2() {
	cout << "cin.get(char&) 사용하여 enter까지 입력 : ";
	char ch;
	while (true) {
		cin.get(ch);
		if (cin.eof()) {
			break;
		}
		cout.put(ch);
		if (ch == '\n') {
			break;
		}
	}
}

int main() {

	get1(); // cin.get()
	get2(); // cin.get(char&)

	return 0;
}