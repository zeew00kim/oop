#include <iostream>
#include <cmath>
using namespace std;

// 숙쁠쁠 실습 4-2 2번 문제
class Circle {
	int radius;
	static int cnt;
public:
	Circle() {
		radius = 0;
	}
	~Circle() {
		cnt++;
		cout << "destruct count of Constructor : " << cnt << endl;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getSize() {
		return 3.14 * pow(radius, 2);
	}
};

int Circle::cnt = 0;

int main() {

	int idxCnt, temp;

	cout << "enter the array index size : ";
	cin >> idxCnt;

	Circle* arr = new Circle[idxCnt];

	for (int i = 0; i < idxCnt; i++) {
		do {
			cout << "radius of Circle arr [" << i << "] : ";
			cin >> temp;
			arr[i].setRadius(temp); 
			if (temp <= 0) {
				cout << "retry it...\n";
			}
		} while (temp <= 0);
	}

	int i = 0;
	int cnt = 0;
	double circSize;
	Circle* p = arr;

	cout << endl;

	while (i < idxCnt) {
		circSize = p[i].getSize();
		cout << "size of Circle arr[" << i << "] : " << circSize << endl;
		if (p[i].getSize() >= 100 && p[i].getSize() <= 200) {
			cnt++;
		}
		i++;
	}

	cout << endl;

	cout << "SELECT count(cnt)AS bounds\nFROM class_Circle\nWHERE size BETWEEN 100 AND 200\n";
	cout << " ----------\n";
	cout << "|  bounds  |\n";
	cout << " ----------\n";
	cout << "|     " << cnt << "    |\n";
	cout << " ----------\n";

	cout << endl;

	delete[] arr;

	return 0;
}