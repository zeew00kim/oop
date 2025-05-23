#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

// 정수 백터 배열에 값을 입력하고 정렬하는 로직

void selectionSort(vector<int>* p, int num) {

	for (int i = 0; i < num - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < num; j++) {
			if (p->at(minIdx) > p->at(j)) {
				minIdx = j;
			}
		}
		int temp = p->at(i);
		p->at(i) = p->at(minIdx);
		p->at(minIdx) = temp;
	}
}

void printVector(vector<int> v, int num) {

	vector<int>::iterator it;
	
	for (it = v.begin(); it != v.end(); it++) {
		int temp = *it;
		cout << temp << " ";
	}
	cout << endl;
}

int main() {

	vector<int> v;
	int num;

	cout << "배열의 길이로 사용할 정수 : ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		int temp;
		cout << i + 1 << " 번째 값 : ";
		cin >> temp;
		v.insert(v.end(), temp);
		/*v.push_back(temp);*/
	}

	selectionSort(&v, num);
	printVector(v, num);

	return 0;
}