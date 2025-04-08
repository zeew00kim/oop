#include <iostream>
using namespace std;

// 숙쁠쁠 6장 실습 4번 문제 : 생성자 함수의 중복 간소화
class Vector {
	int* p;
	int size;
	static int cnt;
public :
	/*Vector() {
		p = new int[100];
		size = 100;
	}
	Vector(int n) {
		p = new int[n];
		size = n;
	}*/
	Vector(int num = 100) {
		p = new int[num];
		size = num;
		cout << num << endl;
	}
	~Vector() {
		cnt++;
		cout << "destroy obj Vector " << cnt << endl;
		delete[] p;
	}
};

int Vector::cnt = 0;

int main() {

	Vector* v1, * v2;
	v1 = new Vector();
	v2 = new Vector(1024);

	delete v1;
	delete v2;

	return 0;
}