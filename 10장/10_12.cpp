#include <iostream>
#include <string>
#include <map>
using namespace std;

// map으로 영한 dictionary = 해시맵 만들기

int main() {

	map<string, string> dict;

	string sel, eng, kor;

	while (true) {

		cout << "영단어를 입력 : ";
		getline(cin, eng);

		if (dict.count(eng) > 0) {
			cout << "이미 존재하는 단어입니다." << endl;
			continue;
		}

		cout << "한글을 입력 : ";
		getline(cin, kor);

		dict.insert(make_pair(eng, kor));

		cout << "추가 입력을 하시겠습니까 (yes|no) : ";
		getline(cin, sel);
		if (sel == "no") {
			cout << "반복문을 종료합니다." << endl;
			break;
		}
	}

	cout << "저장된 map 요소의 개수 : " << dict.size() << endl;

	string trace;

	while (true) {
		
		cout << "탐색할 영단어 : ";
		getline(cin, trace);
		
		if (trace == "exit") {
			break;
		}
		
		if (dict.find(trace) == dict.end()) {
			cout << "존재하지 않는 단어" << endl;
		}
		else {
			cout << "탐색된 한글 단어 : " << dict[trace] << endl;
		}
	}

	return 0;
}