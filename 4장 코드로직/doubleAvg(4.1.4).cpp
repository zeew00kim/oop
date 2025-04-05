#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int num;
	int sum = 0;
	double avg = 0.0;

	do {
		cout << "배열의 길이를 입력 : ";
		cin >> num;
		if (num <= 0) {
			cout << "양수로 다시 입력...\n";
		}
	} while (num <= 0);

	int* arr = new int[num];
	if (!arr) {
		cout << "메모리 할당 실패...\n";
		exit(1);
	}

	for (int i = 0; i < num; i++) {
		cout << "정수를 입력 : ";
		cin >> arr[i];
		sum += arr[i];
	}

	avg = (double)(sum / num);

	cout << "평균 값 : " << avg << endl;

	return 0;
}