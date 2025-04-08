#include <iostream>
using namespace std;

// 숙쁠쁠 6장 실습 2번 문제 : 디폴트 매개변수 가진 함수 만들기
void f(char c = 'X', int line = 5);

void f(char c, int line) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 10; j++) {
			cout << c;
		}
		cout << endl;
	}
}

int main() {

	f();
	f('%');
	f('@', 5);

	return 0;
}