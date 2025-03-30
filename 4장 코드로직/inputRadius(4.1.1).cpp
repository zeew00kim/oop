#include <iostream>
#include <cmath>
using namespace std;

// 숙쁠쁠 실습 4-1 1번 문제
class Circle {
	int radius;
public:
	Circle() {
		radius = 0;
	}
	void setRadius(int r) {
		this->radius = r;
	}
	double getArea() {
		return 3.14 * pow(radius, 2);
	}
};

int main() {

	int num;
	int temp;

	cout << "배열의 길이로 사용할 정수를 입력 : ";
	cin >> num; 

	Circle* circArr = new Circle[num];

	for (int i = 0; i < num; i++) {
		cout << i << " 번째 인덱스의 정수 값 : ";
		cin >> temp;
		circArr[i].setRadius(temp);
		cout << i+1 << " 번째 객체 원의 면적 : " << circArr[i].getArea() << endl;;
	}

	return 0;
}