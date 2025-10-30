#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 배열 A에서 가장 큰 값 - 가장 작은 값 + 1
// 위 방식을 통해 배열 B의 크기를 구한다.
int insertionSort(vector<int> temp) {
	for (int i = 1; i < temp.size(); i++) {
		int key = temp.at(i);
		int j = i - 1;
		while (j >= 0 && temp[j] > key) {
			temp[j + 1] = temp[j];
			j--;
		}
		temp[++j] = key;
	} // 0 0 2 2 3 3 3 5
	int max = temp.back();
	int min = temp.front();
	int cnt = max - min + 1;
	return cnt;
}

int main() {

	vector<int> A = { 2, 5, 3, 0, 2, 3, 0, 3 }, B, C;
	int num = A.front();

	cout << "Input Array A : ";
	for (int data : A) { cout << data << " "; }
	cout << endl;

	// sort() 이딴 건 가오가 상하기 때문에 사용하지 않는다;;;
	int data_cnt = insertionSort(A);
	B.resize(A.size());
	C.resize(data_cnt);

	// 배열 A의 인덱스에 있는 값을 하나씩 읽어가며 배열 C에 counting
	for (int i = 0; i < A.size(); i++) { C.at(A.at(i)) += 1; } 
	
	// 각 인덱스 위치의 값에 바로 앞(이전) 인덱스에 위치한 값을 더함
	for (int i = 1; i < C.size(); i++) { C.at(i) += C.at(i - 1); }

	cout << "Count Array C : ";
	for (int data : C) { cout << data << " "; }
	cout << endl;

	for (int i = A.size() - 1; i >= 0; --i) {
		int idx = C.at(A.at(i)) - 1;
		C.at(A.at(i)) -= 1;
		B.at(idx) = A.at(i);
	}

	cout << "Output Array B : ";
	for (int data : B) { cout << data << " "; }
	cout << endl;

	return 0;
}