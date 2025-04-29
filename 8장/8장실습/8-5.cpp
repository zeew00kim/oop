#include <iostream>
using namespace std;

// 8-5 실습 : 다중 상속 받는 클래스 작성

class Adder {
protected:
	int add(int a, int b) {
		return a + b;
	}
};

class Subtractor {
protected:
	int minus(int a, int b) {
		return a - b;
	}
};

class Multipler {
protected:
	int mul(int a, int b) {
		return a * b;
	}
};

class Divider {
protected:
	int div(int a, int b) {
		if (b == 0) {
			cout << "0으로 나눌 수 없습니다.";
		}
		else {
			return a / b;
		}
	}
};

class Calculator : public Adder, public Subtractor, public Multipler, public Divider {
public:
	int calc(char op, int a, int b, int &result) {
		switch (op) {
		case '+':
			result = add(a, b);
			break;
		case '-':
			result = minus(a, b);
			break;
		case '*':
			result = mul(a, b);
			break;
		case '/':
			result = div(a, b);
			break;
		default:
			cout << "연산자가 잘못 입력되었습니다.\n";
			break;
		}
		if (result == -1 || result == 0) {
			result = 1;
			return result;
		}
		else return result;
	}
};

int main() {

	int a, b;
	int result;

	cout << "a를 입력 : ";
	cin >> a;

	cout << "b를 입력 : ";
	cin >> b;

	Calculator handCalc;

	cout << "a + b = " << handCalc.calc('+', a, b, result) << endl;
	cout << "a - b = " << handCalc.calc('-', a, b, result) << endl;
	cout << "a * b = " << handCalc.calc('*', a, b, result) << endl;
	cout << "a / b = " << handCalc.calc('/', a, b, result) << endl;

	return 0;
}