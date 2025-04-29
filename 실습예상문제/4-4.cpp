#include <iostream>
#include <string>
using namespace std;

// 4-4장 예상문제 : 문자열의 내용을 단어 단위로 오른쪽으로 돌리며 출력

int main() {

    string str;

    cout << "공백이 포함된 문자열을 입력 : ";
    getline(cin, str);

    int len = str.length();
    int spaceCnt = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            spaceCnt++;
        }
    }

    int wordCnt = spaceCnt + 1;
    string *subStr = new string[wordCnt]; // 단어의 개수만큼 
    string temp = ""; // 임시 값 저장용
    int idx = 0; 

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            subStr[idx++] = temp; // 공백을 만나면 누적된 temp 값을 대입
            temp = ""; // 대입 이후 temp 값은 초기화
        }
        else {
            temp += str[i]; // temp에 str[i] 값을 누적
        }
    }
    subStr[idx] = temp; // 마지막 단어를 대입

    for (int i = 0; i < wordCnt; i++) {
        for (int j = 0; j < wordCnt; j++) {
            // 문자열 값을 오른쪽으로 돌리며 출력
            cout << subStr[(wordCnt + j - i) % wordCnt] << " ";
            // 아래 로직은 왼쪽으로 돌리며 출력
            // cout << subStr[(i + j) % wordCnt] << " "; 
        }
        cout << endl;
    }

    delete[] subStr;

    return 0;
}