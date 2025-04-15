#include <iostream>
using namespace std;

// 실습 7-3 : 두 개의 Power 객체를 더하는 += 연산자 작성
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
	Power& operator+= (Power op2);
	Power& operator-= (Power op2);
};

Power& Power::operator+= (Power op2) {
	kick = kick + op2.kick; // this.kick 사용 시 에러 발생
	punch = punch + op2.punch; // 클래스의 객체 자체를 참조
	return *this;
}

Power& Power::operator-= (Power op2) {
	kick = kick - op2.kick; // this.kick 사용 시 에러 발생
	punch = punch - op2.punch; // 클래스의 객체 자체를 참조
	return *this;
}

int main() {

	int arr[2][2];

	for (int i = 0; i < 2; i++) {
		cout << "[ no." << i+1 << " punch & kick value ]\n";
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	Power a(arr[0][0], arr[0][1]);
	Power b(arr[1][0], arr[1][1]);
	Power c, d;

	// 초기 상태
	a.show();
	b.show();

	// a + b 이후
	c = a += b;
	a.show();

	// a - b 이후
	d = a -= b;
	a.show();

	c.show();
	d.show();

	return 0;
}