#include <iostream>
using namespace std;

template <class T>
class Stack {
	int top;
	int cap = 3;
	T* data = new T[cap];
public:
	Stack() {
		cout << "init_stack" << endl;
		top = -1;
	}
	bool is_empty() {
		return (top == -1) ? true : false;
	}
	bool is_full() {
		return (top == cap - 1) ? true : false;
	}
	void push(T element) {
		if (is_full()) {
			cout << "스택 공간 2배 확장" << endl;
			T* temp = new T[cap];
			for (int i = 0; i <= top; i++) {
				temp[i] = data[i];
			}
			cap *= 2;
			delete[] data;
			data = new T[cap];
			for (int i = 0; i <= top; i++) {
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
};

int main() {

	Stack<int*> ipStack;

	int* p = new int[30];

	for (int i = 0; i < 30; i++) {
		p[i] = i * 2;
		ipStack.push(p + i);
	}

	for (int i = 0; i < 30; i++) {
		int* q = ipStack.pop();
		cout << *q << " ";
	}
	cout << endl;

	delete[] p;

	return 0;
}