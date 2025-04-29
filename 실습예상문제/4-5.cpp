#include <iostream>
#include <string>
using namespace std;

// 4-5장 예상 문제 : 덧셈 문자열을 입력 받아 덧셈 실행 (공백을 무시하고)

int main() {

	string str;

	cout << "덧셈 문자열을 입력 : ";
	getline(cin, str);

	int startIdx = 0;
	int sum = 0;

	while (true) {
		int findIdx = str.find('+', startIdx);
		if (findIdx == -1) { // + 연산자를 찾을 수 없다면
			string part = str.substr(startIdx);
			if (part == "") {
				break;
			}
			part.erase(remove(part.begin(), part.end(), ' '), part.end());
			cout << part << endl;
			sum += stoi(part);
			break;
		}
		int cnt = findIdx - startIdx;
		string part = str.substr(startIdx, cnt);
		part.erase(remove(part.begin(), part.end(), ' '), part.end());
		cout << part << endl;
		sum += stoi(part);
		startIdx = findIdx + 1;
	}
	cout << "정수 값들의 덧셈 결과 : " << sum << endl;

	return 0;
}