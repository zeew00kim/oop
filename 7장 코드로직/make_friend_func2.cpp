#include <iostream>
using namespace std;

// 숙쁠쁠 7장 실습 2번 문제 : 다른 클래스의 맴버 함수를 프랜드로 선언
class Rect;  // 컴파일 에러 방지 선언문

class RectManager {
public:
	bool equals(Rect r, Rect s);
};

class Rect {
	int width, height;
public:
	Rect() {
		width = height = 1;
	}
	Rect(int width, int height) {
		this->width = width;
		this->height = height;
	}
	friend bool RectManager::equals(Rect r, Rect s);
	void set_width_height(int w, int h) {
		this->width = w;
		this->height = h;
	}
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int width[2];
	int height[2];

	for (int i = 0; i < 2; i++) {
		cout << "[ rect " << i + 1 << " ]\n";
		cout << "enter the width : ";
		cin >> width[i];
		cout << "enter the height : ";
		cin >> height[i];
	}

	Rect a;
	a.set_width_height(width[0], height[0]);

	Rect b;
	b.set_width_height(width[1], height[1]);

	RectManager man;

	if (man.equals(a, b)) {
		cout << "equals\n";
	}
	else {
		cout << "non-equals\n";
	}

	return 0;
}