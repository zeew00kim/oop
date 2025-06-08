#include <iostream>
#include <string>
using namespace std;

// Point를 상속받은 ColorPrint의 객체를 스트림에 출력하는 연산자 작성

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x = 0, int y = 0, string color = "black") : Point(x, y) {
		this->color = color;
	}
	friend ostream& operator << (ostream& print, ColorPoint obj);
};

ostream& operator << (ostream& print, ColorPoint obj) {
	print << obj.color << ", " << obj.getX() << ", " << obj.getY();
	return print;
}

int main() {

	int x, y;
	string color;

	cout << "색상을 입력 : ";
	getline(cin, color); 

	cout << "좌표 x, y를 입력 : ";
	cin >> x >> y;

	ColorPoint cp(x, y, color);

	cout << cp << endl;

	return 0;
}