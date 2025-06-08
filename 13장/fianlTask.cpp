#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

class Shape {
protected:
	Shape* next;
public:
	Shape() {
		next = NULL;
	}
	void setNext(Shape* p) {
		next = p;
	}
	Shape* getNext() {
		return next;
	}
	virtual void print(ostream& show) = 0;
	virtual ~Shape() {}

	friend ostream& operator << (ostream& show, Shape& s);
};

ostream& operator << (ostream& show, Shape& s) {
	s.print(show);
	return show;
}

class Line : public Shape {
	int length;
public:
	void setLength(int length) {
		this->length = length;
	}
	void print(ostream& show) {
		show << "Line (length : " << length << ")" << endl;
	}
};

class Circle : public Shape {
	int radius;
public:
	void setRadius(int radius) {
		this->radius = radius;
	}
	void print(ostream& show) {
		show << "Circle (radius : " << radius << ")" << endl;
	}
};

class Rect : public Shape {
	int width, height;
public:
	void setSize(int width, int height) {
		this->width = width;
		this->height = height;
	}
	void print(ostream& show) {
		show << "Rectangle (width : " << width
			<< ", height : " << height << ")" << endl;
	}
};

int main() {

	int length, radius, width, height;
	int sel;

	Shape* start = NULL;
	Shape* last = NULL;

	while (true) {
		do {
			try {
				cout << "[1. Line | 2. Circle | 3. Rect | 4. EXIT]\n";
				cin >> sel;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					string error = "[ InputMismatchException e ]";
					throw error;
				}
			}
			catch (string str) {
				cout << str << endl;
				cout << "정수로 다시 입력" << endl;
				sel = -1;
			}
			if (sel > 4 || sel < 1) {
				cout << "범위 이내의 값으로 재입력" << endl;
			}
		} while (sel > 4 || sel < 1);

		if (sel == 4) {
			cout << "프로그램 종료" << endl;
			break;
		}
		else if (start == NULL) {
			switch (sel) {
			case 1:
				cout << "length 값을 입력 : ";
				cin >> length;
				start = new Line();
				((Line*)start)->setLength(length);
				break; 
			case 2:
				cout << "radius 값을 입력 : ";
				cin >> radius;
				start = new Circle();
				((Circle*)start)->setRadius(radius);
				break;
			case 3:
				cout << "width, height 값을 입력 : ";
				cin >> width >> height;
				start = new Rect();
				((Rect*)start)->setSize(width, height);
				break;
			default:
				cout << "코드에 문제가 있음" << endl;
				exit(-1);
			}
			last = start;
		}
		else {
			switch (sel) {
			case 1:
				cout << "length 값을 입력 : ";
				cin >> length;
				last->setNext(new Line());
				last = last->getNext();
				((Line*)last)->setLength(length);
				break;
			case 2:
				cout << "radius 값을 입력 : ";
				cin >> radius;
				last->setNext(new Circle());
				last = last->getNext();
				((Circle*)last)->setRadius(radius);
				break;
			case 3:
				cout << "width, height 값을 입력 : ";
				cin >> width >> height;
				last->setNext(new Rect());
				last = last->getNext();
				((Rect*)last)->setSize(width, height);
				break;
			default:
				cout << "코드에 문제가 있음" << endl;
				exit(-1);
			}
		}
	}

	ofstream fout("2022158067.txt");

	cout << "\n[ 입력된 순서 ]\n" << endl;

	Shape* p = start;
	while (p != NULL) {
		p->print(cout);
		p->print(fout);
		p = p->getNext();
	}
	fout.close();

	cout << "\n[ 파일 내용 출력 ]\n" << endl;
	ifstream fin;
	fin.open("2022158067.txt");
	string line;

	while (getline(fin, line)) {
		cout << line << endl;
	}
	fin.close();

	p = start;
	while (p != NULL) {
		Shape* temp = p->getNext();
		delete p;
		p = temp;
	}

	return 0;
}