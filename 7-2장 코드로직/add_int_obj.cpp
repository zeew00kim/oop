#include <iostream>
using namespace std;

// 실습 7-4 : 객체와 정수를 더하는 연산자 작성 실습
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
	Power operator+ (int op2); 
};

// 리턴 타입이 Power이다.
Power Power::operator+ (int op2) {
	Power temp;
	temp.kick = kick + op2;
	temp.punch = punch + op2;
	return temp;
}

int main() {

	Power a(3, 5), b;

	// 초기 상태
	a.show();
	b.show();

	b = a + 2;

	a.show();
	b.show();

	return 0;
}