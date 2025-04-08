#include <iostream>
using namespace std;

// 숙쁠쁠 6장 실습 1번 문제 : sum() 함수 중복 연습
int sum(int a, int b) {
	int s = 0;
	
	if (a < b) {
		for (int i = a; i <= b; i++) {
			s += i;
		}
	}
	else {
		for (int i = b; i <= a; i++) {
			s += i;
		}
	}
	return s;
}

int sum(int a) {
	int s = 0;
	for (int i = 0; i <= a; i++) {
		s += i;
	}
	return s;
}

int main() {

	cout << sum(5, 3) << endl;
	cout << sum(3) << endl;
	cout << sum(100) << endl;

	return 0;
}