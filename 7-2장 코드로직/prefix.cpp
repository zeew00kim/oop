#include <iostream>
using namespace std;

// 실습 7-5 : 전위 연산자 작성
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show() {
		cout << "kick = " << kick << ", " << "punch = " << punch << endl;
	}
	Power& operator++ (); // 전위 연산자는 매개변수 값이 없음
	Power& operator-- ();
};

Power& Power::operator++ () {
	kick++;
	punch++;
	return *this; // 변경된 객체 자신(Power a)를 참조 리턴
}

Power& Power::operator-- () {
	kick--;
	punch--;
	return *this; // 변경된 객체 자신(Power a)를 참조 리턴
}

int main() {

	Power a(3, 5), b;

	// 초기 상태
	a.show();
	b.show();

	b = ++a;
	b.show();

	b = --a;
	b.show();

	return 0;
}