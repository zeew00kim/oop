#include <iostream>
#include <string>
using namespace std;

// 숙쁠쁠 실습 4-2 5번 문제
int main() {

    string str;

    cout << "덧셈 연산의 문자열을 입력 : ";
    cin >> str;

    int startIdx = 0;
    int sum = 0;

    while(true) {
        int findIdx = str.find('+', startIdx);
        if (findIdx == -1) {
            string part = str.substr(startIdx);
            if (part == "") {
                break;
            }
            cout << part << endl;
            sum += stoi(part);
            break;
        }
        int cnt = findIdx - startIdx;
        string part = str.substr(startIdx, cnt);
        cout << part << endl;
        sum += stoi(part);
        startIdx = findIdx + 1;
    }
    cout << "정수 값들의 덧셈 결과 : " << sum << endl;

    return 0;
}