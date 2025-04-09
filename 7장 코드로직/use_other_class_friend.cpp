#include <iostream>
using namespace std;

// 숙쁠쁠 7장 실습 3번 문제 : 다른 클래스 전체를 프랜드로 선언
class Rect;  // 컴파일 에러 방지 선언문

class RectManager {
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
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
	friend RectManager;
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) {
		return true;
	}
	else {
		return false;
	}
}

void RectManager::copy(Rect& dest, Rect& src) {
	dest.width = src.width;
	dest.height = src.height;
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

	Rect a(width[0], height[0]);
	Rect b(width[1], height[1]);
	RectManager man;

	man.copy(b, a);
	
	if (man.equals(a, b)) {
		cout << "equals\n";
	}
	else {
		cout << "non-equals\n";
	}

	return 0;
}