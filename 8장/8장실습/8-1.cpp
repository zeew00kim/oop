#include <iostream>
#include <string>
using namespace std;

// 실습 8-1 : Point 클래스를 상속받는 ColorPoint 클래스 만들기

class Point {
	int x, y;
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void showPoint() {
		cout << "x = " << x << ", y = " << y << endl;
	}
};

class ColorPoint:public Point {
	string  color;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint() {
		cout << color << " : ";
		showPoint();
	}
};

int main() {

	int x, y;
	string color;

	cout << "enter the x, y, color : ";
	cin >> x >> y >> color;

	Point p;
	ColorPoint cp;
	cp.set(x, y);
	cp.setColor(color);
	cp.showColorPoint();

	return 0;
}