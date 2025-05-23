#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 백터 문자열을 만들고 사전상 우선순위 비교 및 이름이 입력된 순서 찾기

int main() {

	vector<string> strVec;
	string name, last, first;

	cout << "[ 이름을 3개 입력 ]" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " : ";
		getline(cin, name);
		strVec.push_back(name);
	}

	last = strVec.at(0);

	for (int i = 0; i < 3; i++) {
		if (last < strVec[i]) {
			last = strVec[i];
		}
	}

	cout << "사전상 가장 뒤에 나오는 이름 : " << last << endl;
	int findIdx;
	for (int i = 0; i < 3; i++) {
		if (strVec[i] == last) {
			findIdx = i;
		}
	}
	cout << "이름이 입력된 순서 : " << findIdx << endl;
	
	first = strVec.at(0);

	for (int i = 0; i < 3; i++) {
		if (first > strVec[i]) {
			first = strVec[i];
		}
	}

	cout << "사전상 가장 먼저 나오는 이름 : " << first << endl;
	for (int i = 0; i < 3; i++) {
		if (strVec[i] == first) {
			findIdx = i;
		}
	}
	cout << "이름이 입력된 순서 : " << findIdx << endl;

	return 0;
}