#include <iostream>
#include <cmath>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	double getSize();
};

Circle::Circle() : Circle(radius) {} // 위임 생성자

Circle::Circle(int r)
	: radius(r) {}

double Circle::getSize() {
	return 3.14 * pow(radius, 2); // 타겟 생성자
}

int main() {

	Circle circ1;

	do {
		cout << "enter the integer : ";
		cin >> circ1.radius;
		if (circ1.radius < 0) {
			cout << "retry it...\n";
		}
	} while (circ1.radius < 0);

	cout << "size of circ1 : " << circ1.getSize() << endl;

	Circle circ2(20);
	cout << "size of circ2 : " << circ2.getSize() << endl;

	return 0;
}