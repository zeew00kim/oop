#include <iostream>
#include <string>
using namespace std;

// 실습 8-2 : protected 맴버에 대한 접근

class Point {
	int x, y;
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	void showPoint() {
		cout << "x = " << x << ", y = " << y << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint() {
		cout << color << " : ";
		showPoint();
	}
	string getColor() const {
		return color;
	}
	bool equals(const ColorPoint& p) {
		if (getX() == p.getX() &&
			getY() == p.getY() &&
			color == p.color) {
			return true;
		}
		return false;
	}
};

int main() {

	Point p;
	p.set(2, 3);
	p.showPoint();

	ColorPoint cp;

	cp.set(10, 10);
	cp.setColor("RED");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("BLUE");

	cout << ((cp.equals(cp2)) ? "true" : "false");

	return 0;
}