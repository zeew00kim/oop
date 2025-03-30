#include <iostream>
#include <cmath>
using namespace std;

// 숙쁠쁠 실습 4-1 2번 문제
class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * pow(radius, 2);
	}
};

int main() {

	int a, b;

	cout << "정수 두 개를 입력 : ";
	cin >> a >> b;

	Circle circArr[3];

	circArr[0].setRadius(a);
	circArr[1].setRadius(b);
	circArr[2] = Circle();

	for (int i = 0; i < 3; i++) {
		if (circArr[i].getArea() != 3.14) {
			cout << "Circle " << i << "의 면적은 : " << circArr[i].getArea() << endl;
		}
	}

	return 0;
}