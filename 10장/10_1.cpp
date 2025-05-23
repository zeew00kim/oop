#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) {
		this->radius = radius;
	}
	int getRadius() {
		return radius;
	}
};

template <class T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {

	int a, b;

	cout << "a, b 값을 입력 : ";
	cin >> a >> b;

	mySwap(a, b);
	cout << a << ", " << b << endl;

	double a2, b2;

	cout << "a2, b2 값을 입력 : ";
	cin >> a2 >> b2;

	mySwap(a2, b2);
	cout << a2 << ", " << b2 << endl;

	Circle donut(5), pizza(20);
	mySwap(donut, pizza);

	cout << pizza.getRadius() << ", " << donut.getRadius() << endl;

	return 0;
}