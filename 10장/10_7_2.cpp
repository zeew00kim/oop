#include <iostream>
#include <string>
using namespace std;

// 스택 클래스를 구현하고 overflow 될 경우 2배씩 증가되는 스택

template <class T>
class MyStack {
	int top, len = 10;
	T *data;
public:
	MyStack() {
		top = -1;
		data = new T[len];
	}
	void push(T element) {
		if (is_full()) {
			len *= 2;
			T* temp = new T[len];
			for (int i = 0; i < len / 2; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = new T[len];
			for (int i = 0; i < len / 2; i++) {
				data[i] = temp[i];
			}
			delete[] temp;
		}
		data[++top] = element;
	}
	T pop() {
		if (is_empty()) {
			cout << "stack underflow" << endl;
			return 0;
		}
		return data[top--];
	}
	bool is_empty() {
		return (top == -1) ? true : false;
	}
	bool is_full() {
		return (top >= len -1) ? true : false;
	}
};

int main() {

	MyStack<int> iStack;

	int len = 20;

	int* p = new int[len];

	for (int i = 0; i < len; i++) {
		p[i] = i * 10;
		iStack.push(p[i]);
	}

	for (int i = 0; i < len; i++) {
		cout << iStack.pop() << endl;
	}
	cout << endl;

	delete[] p;

	return 0;
}