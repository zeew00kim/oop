#include  <iostream>
#include <cmath>
using namespace std;

// 9_2 실습 : 자바 실기셤이랑 비슷함

class Shape {
	Shape* next;
protected:
	virtual void draw() {
		cout << "[  Shape  ]" << endl;
	}
public:
	Shape() {
		next = NULL;
	}
	virtual ~Shape() {}
	void paint() {
		draw();
	}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	Shape* getNext() {
		return next;
	}
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

int main() {

	int sel;
	int cnt = 0;

	Shape* pStart = NULL;
	Shape* pLast = NULL;

	while (cnt < 4) {
		do {
			cout << "[ 1. Line | 2. Circle | 3. Rect ] : ";
			cin >> sel;
			if (sel > 3 || sel < 1) {
				cout << "재입력\n";
			}
		} while (sel > 3 || sel < 1);

		if (pStart == NULL) {
			switch (sel) {
			case 1:
				pStart = new Line();
				break;
			case 2:
				pStart = new Circle();
				break;
			case 3:
				pStart = new Rect();
				break;
			}
			pLast = pStart;
		}

		else {
			switch (sel) {
			case 1:
				pLast = pLast->add(new Line());
				break;
			case 2:
				pLast = pLast->add(new Circle());
				break;
			case 3:
				pLast = pLast->add(new Rect());
				break;
			}
		}

		cnt++;
	}

	Shape* p = pStart;
	while (p != NULL) {
		p->paint();
		p = p->getNext();
	}

	p = pStart;
	while (p != NULL) {
		Shape* temp = p->getNext();
		delete p;
		p = temp;
	}

	return 0;
}