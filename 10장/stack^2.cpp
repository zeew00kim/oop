#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

template <class T>
class MyStack {
	int top;
	int max = 10;
	T *data;
public:
	MyStack();
	bool is_empty();
	bool is_full();
	void push(T element) {
		if (is_full()) {
			printf("스택 공간 2배 증가 (%d * %d = %d)\n", max, 2, max * 2);
			max *= 2;
			T* temp = new T[max];
			for (int i = 0; i < (max / 2); i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = new T[max];
			for (int i = 0; i < (max / 2); i++) {
				data[i] = temp[i];
			}
			delete[] temp;
		}
		data[++top] = element;
	}
	T pop() {
		if (is_empty()) {
			cout << "stack underflow" << endl;
			exit(-1);
		}
		return data[top--];
	}
};

template <class T>
MyStack<T>::MyStack() {
	top = -1;
	data = new T[max];
}

template <class T>
bool MyStack<T>::is_empty() {
	return (top == -1) ? true : false;
}

template <class T>
bool MyStack<T>::is_full() {
	return (top == max - 1) ? true : false;
}

int main() {

	srand(time(NULL));

	MyStack<int> iStack;

	int len;

	cout << "enter the len : ";
	cin >> len;

	int* arr = new int[len];

	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100 + 1;
		iStack.push(arr[i]);
	}

	for (int i = 0; i < len; i++) {
		cout << iStack.pop() << " ";
		if ((i + 1) % 10 == 0 && i != 0) {
			cout << endl;
		}
	}
	cout << endl;

	delete[] arr;

	return 0;
}