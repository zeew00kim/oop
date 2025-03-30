#include <iostream>
#include <string>
using namespace std;

// 숙쁠쁠 실습 4-2 6번 문제
int main() {

    string str;
    string find, replace;
    int startIdx = 0;

    cout << "enter the lots of string (end symbol is `&`) : ";
    getline(cin, str, '&');
    cin.ignore();

    cout << endl;
    cout << "enter the string find : ";
    getline(cin, find);
    cout << "enter the string replace : ";
    getline(cin, replace);

    while(true) {
        int findIdx = str.find(find, startIdx);
        if (findIdx == -1) {
            break;
        }
        str.replace(findIdx, find.length(), replace);
        startIdx = findIdx + replace.length();
    }
    cout << str << endl;

    return 0;
}