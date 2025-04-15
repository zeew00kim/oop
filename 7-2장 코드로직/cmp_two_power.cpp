#include <iostream>
using namespace std;

// 실습 7-2 : 두 개의 Power 객체를 비교하는 == 연산자 작성
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
	bool operator== (Power op2);
};

bool Power::operator== (Power op2) {
	if (kick == op2.kick && punch == op2.punch) {
		return true;
	}
	else return false;
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

	a.show();
	b.show();

	if (a == b) {
		cout << "a and b are same\n";
	}
	else cout << "a and b are not same\n";

	return 0;
}