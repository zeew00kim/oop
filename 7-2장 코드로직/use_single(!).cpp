#include <iostream>
using namespace std;

// 실습 7-6 : 단항 연산자 (!) 작성
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
	bool operator! ();
};

bool Power::operator! () {
	if (kick == 0 && punch == 0) {
		return true;
	}
	else return false;
}

int main() {

	Power a(0, 0), b(5, 5);
	
	if (!a) {
		cout << "power of a = 0\n";
	}
	else cout << "power of a in not zero\n";

	if (!b) {
		cout << "power of b = 0\n";
	}
	else cout << "power of b in not zero\n";

	return 0;
}