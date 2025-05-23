#include <iostream>
using namespace std;

template <class T>
T total(T *data, int num) {
	T sum = 0;
	for (int i = 0; i < num; i++) {
		sum += data[i];
	}
	return sum;
}

template <class T>
T avg(T* data, int num) {
	T sum = 0;
	for (int i = 0; i < num; i++) {
		sum += data[i];
	}
	return sum / num;
}

int main() {

	int a[] = { 1, 2, 3, 4, 5 };
	double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6 };

	int size = sizeof(a) / sizeof(a[0]);

	cout << "sum of x[] = " << total(a, size) << endl;
	cout << "sum of d[] = " << total(d, size) << endl;

	cout << "avg of x[] = " << avg(a, size) << endl;
	cout << "avg of d[] = " << avg(d, size) << endl;

	return 0;
}