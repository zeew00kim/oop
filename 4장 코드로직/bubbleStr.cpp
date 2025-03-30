#include <iostream>
#include <string>
using namespace std;

// 숙쁠쁠 실습 4-2 3번 문제
void printString(string *name, int num);

int main() {

	int num;

	cout << "enter the size of String : ";
	cin >> num;
	cin.ignore();

	string* name = new string[num];

	for (int i = 0; i < num; i++) {
		cout << "enter the name : ";
		getline(cin, name[i], '\n');
		if (name[i] == "") {
			cout << "program off...\n";
			break;
		}
	}

	string latter = name[0];

	int swapCnt;

	for (int i = 0; i < num; i++) {
		swapCnt = 0;
		for (int j = 0; j < num - i - 1; j++) {
			if (name[j] > name[j + 1]) {
				string temp = name[j];
				name[j] = name[j + 1];
				name[j + 1] = temp;
				swapCnt++;
			}
		}
		if (swapCnt == 0) {
			break;
		}
	}

	printString(name, num);

	delete[] name;

	return 0;
}

void printString(string* name, int num) {

	int i = 0;

	while (i < num) {
		if (name[i] != "\0") {
			cout << "arr[" << i << "] = " << name[i] << endl;
		}
		i++;
	}
}