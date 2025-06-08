#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
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
	friend istream& operator >> (istream& input, ColorPoint& point);
	friend ostream& operator << (ostream& print, ColorPoint& point);
};

istream& operator >> (istream& input, ColorPoint& point) {
	int x, y;
	string color;
	
	cout << "색상 : ";
	getline(input, color);

	cout << "x 좌표 : ";
	input >> x;

	cout << "y 좌표 : ";
	input >> y; 

	point.setX(x);
	point.setY(y);
	point.color = color;

	return input;
}

ostream& operator <<  (ostream& print, ColorPoint& point) {
	print << point.color << ", " << point.getX() << ", " << point.getY();
	return print;
}

int main() { 

	ColorPoint cp;
	cin >> cp;
	cout << cp << endl;

	return 0;
}