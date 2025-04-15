#include <iostream>
using namespace std;

// 실습 7-1 : 두 개의 Power 객체를 더하는 + 연산자 작성
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
	Power operator+ (Power op2);
	Power operator- (Power op2);
};

Power Power::operator+ (Power op2) {
	Power temp;
	temp.kick = this->kick + op2.kick;
	temp.punch = this->punch + op2.punch;
	return temp;
}

Power Power::operator- (Power op2) {
	Power temp;
	temp.kick = this->kick - op2.kick;
	temp.punch = this->punch - op2.punch;
	return temp;
}

int main() {

	int punchA, punchB;
	int kickA, kickB;

	cout << "enter the punch & kick value of a : ";
	cin >> punchA >> kickA;

	cout << "enter the punch & kick value of b : ";
	cin >> punchB >> kickB;

	Power a(punchA, kickA), b(punchB, kickB), c, d;
	
	c = a + b;
	d = a - b;

	a.show();
	b.show();
	c.show();
	d.show();

	return 0;
}