#include <iostream>
#include <cmath>
using namespace std;

// 9장 실습 : 9_1 

class Shape {
public:
	virtual void draw() {
		cout << "Shape --> ";
	}
};

class Circle : public Shape {
	int radius;
public:
	Circle(int radius = 1) {
		this->radius = radius;
	}
	void draw() {
		Shape::draw();
		cout << "circle's area : " << getArea() << endl;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * pow(radius, 2);
	}
};

class Rect : public Shape {
	int width, height;
public:
	Rect(int width = 1, int height = 1) {
		this->height = height;
		this->width = width;
	}
	void draw() {
		Shape::draw();
		cout << "Rect's area : " << getArea() << endl;
	}
	void setSize(int width, int height) {
		this->height = height;
		this->width = width;
	}
	int getArea() {
		return width * height;
	}
};

int main() {

	int radius, width, height;

	Circle circ;
	Rect rect;

	do {
		cout << "반지름을 입력 : ";
		cin >> radius;
		if (radius <= 0) {
			cout << "양수로 재입력\n";
		}
	} while (radius <= 0);

	circ.setRadius(radius);

	do {
		cout << "너비와 높이를 입력 : ";
		cin >> width >> height;
		if (width <= 0 || height <= 0) {
			cout << "양수로 재입력\n";
		}
	} while (width <= 0 || height <= 0);

	rect.setSize(width, height);

	Shape* pShape;
	pShape = &circ;
	pShape->draw();

	pShape = &rect;
	pShape->draw();

	pShape->Shape::draw();
	cout << "프로그램 종료\n";

	return 0;
}