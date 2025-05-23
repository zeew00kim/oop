#include <iostream>
#include <string>
using namespace std;

// 1차 실습 2번 문제

class adder {
protected:
	int add(int a, int b) {
		return a + b;
	}
};

class sub {
protected:
	int min(int a, int b) {
		return a - b;
	}
};

class mul {
protected:
	int m(int a, int b) {
		return a * b;
	}
};

class div {
protected:
	int d(int a, int b) {
		if (b == 0) {
			cout << "0으로 나눌 수 없습니다.";
			return 0;
		}
		return a / b;
	}
};

class calculator : public adder, public sub, public mul, public div {
public:
	int calc(char op, int a, int b, int& res);
	~calculator() {
		cout << "소멸자 실행\n";
	}
};

int calculator::calc(char op, int a, int b, int& res) {
	switch (op) {
	case '+':
		res = add(a, b);
		break;
	case '-':
		res = min(a, b);
		break;
	case '*':
		res = m(a, b);
		break;
	case '/':
		res = d(a, b);
		break;
	default:
		cout << "연산자 입력 오류\n";
		break;
	}
	return res;
}

int main() {

	int a, b;
	int res = 0;

	do {
		cout << "a, b 값을 입력 : ";
		cin >> a >> b;

		calculator temp;

		cout << "a + b : " << temp.calc('+', a, b, res) << endl;
		cout << "a - b : " << temp.calc('-', a, b, res) << endl;
		cout << "a * b : " << temp.calc('*', a, b, res) << endl;
		cout << "a / b : " << temp.calc('/', a, b, res) << endl;

		if (res == 0) {
			cout << "결과가 0입니다. 다시 입력하세요.\n";
		}
	} while (res == 0);

	return 0;
}