#include <iostream>
using namespace std;

class Rect {
	int width, height;
public:
	Rect();
	Rect(int w, int h);
	Rect(int length);
	bool isSquare();
};

Rect::Rect() {
	cout << "[ enter the first rect's w, h ]\n";
	cin >> width;
	cin >> height;
}

Rect::Rect(int w, int h)
	: width(w), height(h) {}

Rect::Rect(int length) {
	width = height = length;
 }

bool Rect::isSquare() {
	return (width - height == 0) ? true : false;
}

int main() {

	int w, h;

	cout << "[ enter the second rect's w, h ]\n";
	cin >> w;
	cin >> h;

	Rect rect1;
	Rect rect2(w, h);
	Rect rect3(w);

	if (rect1.isSquare() == 1) {
		cout << "rect1 is square!!!\n";
	}
	else {
		cout << "rect1 is Non-square...\n";
	}

	if (rect2.isSquare() == 1) {
		cout << "rect2 is square!!!\n";
	}
	else {
		cout << "rect2 is Non-square...\n";
	}

	if (rect3.isSquare() == 1) {
		cout << "rect3 is square!!!\n";
	}
	else {
		cout << "rect3 is Non-square...\n";
	}

	return 0;
}