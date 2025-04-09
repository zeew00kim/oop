#include <iostream>
using namespace std;

// 숙쁠쁠 6-2장 실습 1번 문제 : static 맴버를 가진 Math 클래스 작성
class Math {
public:
	static int abs(int a) {
		return a > 0 ? a : -a;
	}
	static int max(int a, int b) {
		return (a > b) ? a : b;
	}
	static int min(int a, int b) {
		return (a > b) ? b : a;
	}
	static int diff(int a, int b) {
		if (a < b) {
			int temp = a;
			a = b;
			b = temp;
			return a - b;
		}
		else {
			return a - b;
		}
	}
};

int main() {

	int sel;

	cout << "[ choose the option ]\n";
	cout << "1. ABS\n";
	cout << "2. MAX\n";
	cout << "3. MIN\n";
	cout << "4. DIFF\n";
	cout << "5. QUIT\n";

	do {
		cout << "your choice : ";
		cin >> sel;
		if (sel != 5) {
			switch (sel) {
			case 1:
				cout << "your selection is get ABS\n";
				cout << Math::abs(-5) << endl;
				break;
			case 2:
				cout << "your selection is get max\n";
				cout << Math::max(10, 8) << endl;
				break;
			case 3:
				cout << "your selection is get min\n";
				cout << Math::min(-3, -8) << endl;
				break;
			case 4:
				cout << "your selection is get diff\n";
				cout << Math::diff(10, 20) << endl;
				break;
			}
		}
		else if (sel == 5) {
			cout << "out of program...\n";
		}
	} while (sel != 5);

	return 0;
}