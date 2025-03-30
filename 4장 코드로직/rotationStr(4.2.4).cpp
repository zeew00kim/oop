#include <iostream>
#include <string>
using namespace std;

// 숙쁠쁠 실습 4-2 4번 문제
int main() {

    string str;

    cout << "enter the string : ";
    getline(cin, str);

    int len = str.length();
    int spaceCnt = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            spaceCnt++;
        }
    }

    int wordCnt = spaceCnt + 1;
    string *strArr = new string[wordCnt];
    string temp = "";
    int idx = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            strArr[idx++] = temp;
            temp = "";
        }
        else {
            temp += str[i];
        }
    }
    strArr[idx] = temp;

    for (int i = 0; i < wordCnt; i++) {
        for (int j = 0; j < wordCnt; j++) {
            cout << strArr[(i + j) % wordCnt] << " ";
        }
        cout << endl;
    }

    delete[] strArr;

    return 0;
}