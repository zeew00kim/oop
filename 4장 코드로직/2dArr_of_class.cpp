#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

// 숙쁠쁠 실습 4-1 3번 문제
class Circle {
	int radius;
public:
	Circle() {
		radius = 0;
	}
	void getRadius(int r) {
		this->radius = r;
	}
	double getArea() {
		return 3.14 * pow(radius, 2);
	}
};

void printArr(Circle(* circ)[3]);

int main() {

	srand(time(NULL));

	Circle circ[2][3];
	int temp;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			temp = rand() % 10 + 1;
			circ[i][j].getRadius(temp);
		}
	}

	printArr(circ);

	return 0;
}

void printArr(Circle(* circ)[3]) {

	for (int i = 0; i < 2; i++) {
		cout << "size of circ[" << i << "] = { ";
		for (int j = 0; j < 3; j++) {
			cout << circ[i][j].getArea();
			if (j != 2) {
				cout << ", ";
			}
			else if (j == 2) {
				cout << " }\n";
			}
		}
	}
}