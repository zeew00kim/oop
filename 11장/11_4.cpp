#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// getline을 이용해 문자열 입력 후 저장소에 복사
// 복사할 문자열 공간이 부족하다면 증가시키는 로직

int main() {

	int num, i = 0;

	cout << "문자열의 길이를 입력 : ";
	cin >> num;
	cin.ignore(1);

	char *line = new char[num];
	char* warehouse[5] = { nullptr };

	// 저장소 문자열의 모든 인덱스 값들을 공백으로 초기화
	for (int i = 0; i < 5; i++) {
		warehouse[i] = new char[10];
		for (int j = 0; j < 10; j++) {
			warehouse[i][j] = '\0';
		}
	}

	// 원하는 만큼 문자열을 입력
	while (true) {
		cout << i + 1 << " 번째 문자열 입력 : ";
		cin.getline(line, num);

		if (strcmp(line, "exit") == 0) {
			cout << "프로그램 종료" << endl;
			break;
		}

		// 저장소 문자열에 공간이 있다면 복사
		if (warehouse[4][0] == '\0') {
			cout << "여유 공간이 있으므로 문자열 복사" << endl;
			if (strlen(line) > strlen(warehouse[i])) {
				int len = strlen(line) + 1;
				warehouse[i] = new char[len];
				strcpy(warehouse[i], line);
			}
		}

		i++;
	}

	// 저장소 문자열의 문자열들을 모두 출력
	for (int i = 0; i < 5; i++) {
		if (warehouse[i][0] == '\0') {
			for (int j = 0; j < 1; j++) {
				delete[] warehouse[j];
			}
			break;
		}
		cout << i + 1 << " 번째 문자열 : " << warehouse[i] << endl;
	}

	delete[] line;

	return 0;
}