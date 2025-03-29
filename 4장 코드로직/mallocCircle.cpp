#include <iostream>
#include <cmath>
using namespace std;

// 숙쁠쁠 실습 4-2 1번 문제

class Circle {
    int radius;
    static int cnt;
public:
    Circle() {
        radius = 0;
    }
    ~Circle() {
        cnt++;
        cout << "destruct of constructor no." << cnt << endl;
    }
    void setRadius(int radius) {
        this->radius = radius;
    }
    double getSize() {
        return 3.14 * pow(radius, 2);
    }
};

int Circle::cnt = 0;

int main() {

    int idxCnt;
    int temp;

    cout << "enter the array index count : ";
    cin >> idxCnt;

    Circle* arr = new Circle[idxCnt];

    for (int i = 0; i < idxCnt; i++) {
        do {
            cout << "enter the value of no." << i << " idx : ";
            cin >> temp;
            arr[i].setRadius(temp);
            if (temp == 0) {
                cout << "your input value is zer0 retry it...\n";
            }
            else if (temp < 0) {
                cout << "your input value is negative-integer...\n";
            }
        } while (temp <= 0);
    }

    cout << endl;

    Circle* p;
    p = arr;

    int i = 0;

    while (i < idxCnt) {
        cout << "get size of Circle arr[" << i << "] = " << p->getSize() << endl;
        p++;
        i++;
        if (i == idxCnt) {
            cout << endl;
        }
    }

    delete[] arr;

    return 0;
}