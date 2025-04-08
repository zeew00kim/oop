#include <iostream>
#include <string>
// #include <algorithm> // 이걸 쓰면 swap 함수 구현 안해도 됨
using namespace std;

// 숙쁠쁠 실습 5-2 4 번째 문제 : 참조에 의한 호출로 strcmp
int main() {

	int size;

	cout << "enter the size of string : ";
	cin >> size;
	cin.ignore();

	string *name = new string[size];

	for (int i = 0; i < size; i++) {
		cout << "enter the std name : ";
		getline(cin, name[i], '\n');
	}

    // selectionSort 방식을 사용
	for (int i = 0; i < size - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < size; j++) {
			if (name[minIdx] < name[j]) {
				minIdx = j;
			}
		}
		swap(name[i], name[minIdx]);
	}
	
	cout << "most latest string : " << name[0] << endl;

    delete[] name;

	return 0;
}

void swap(string& name1, string& name2) {

	string temp = name1;
	name1 = name2;
	name2 = temp;
}