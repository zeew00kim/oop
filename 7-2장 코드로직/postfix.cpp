#include <iostream>
using namespace std;

// 실습 7-7 : 후위 증감 연산자 작성
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
	Power operator++ (int x);
	Power operator-- (int x);
};

Power Power::operator++ (int x) {
	Power temp = *this; // 증가하기 이전 객체 상태 저장
	kick++;
	punch++;
	return temp;
}

Power Power::operator-- (int x) {
	Power temp = *this; // 감소하기 이전 객체 상태 저장
	kick--;
	punch--;
	return temp;
}

int main() {

	Power a(0, 0), b;
	
	a.show();
	b.show();
	
	b = a++;

	a.show(); // 증가된 값 출력
	b.show(); // 증가 이전 값 출력

	b = a--;
	b.show(); // 감소 이전 값 출력

	return 0;
}