#include <iostream>
using namespace std;

// 아래의 함수 중복을 디폴트 매개변수를 가진 하나의 함수로 변경
//void fillLine() {
//	for (int i = 0; i < 25; i++) {
//		cout << '*';
//	}
//	cout << endl;
//}
//
//void fillLine(int n, char c) {
//	for (int i = 0; i < n; i++) {
//		cout << c;
//	}
//	cout << endl;
//}

void fillLine(int n = 25, char c = '*') {
	for (int i = 0; i < n; i++) {
		cout << c;
	}
	cout << endl;
}


int main() {

	fillLine();
	fillLine(10, '%');

	return 0;
}