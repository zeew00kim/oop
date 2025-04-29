#include <iostream>
#include <string>
using namespace std;

int main() {

	string str, find, replace;

	cout << "여러 문자열을 입력 (& 입력 시 종료) : ";
	getline(cin, str, '&');
	cin.ignore();

	string cycle = "";

	while (true) {
		cout << "교체할 문자열을 탐색 : ";
		getline(cin, find);

		int findIdx = str.find(find);

		if (findIdx == -1) {
			cout << "존재하지 않는 문자열입니다.\n";
			continue;
		}

		cout << "새로운 문자열을 입력 : ";
		getline(cin, replace);

		str.replace(findIdx, find.length(), replace);

		cout << "변경된 문자열 : " << str << endl;
		cout << "추가 진행 여부 (yes/no) : ";
		getline(cin, cycle);

		if (cycle == "no") {
			cout << "프로그램을 종료합니다...\n";
			break;
		}
	}

	return 0;
}