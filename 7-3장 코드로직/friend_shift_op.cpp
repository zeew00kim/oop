// 7-3장 : 참조를 리턴하는 >> 연산자 작성

#include <iostream>
using namespace std;

class Power {
    int kick, punch;
public:
    Power(int kick = 0, int punch = 0) {
        this->kick = kick;
        this->punch = punch;
    }
    void show() {
        cout << "kick = " << kick << ", punch = " << punch << endl;
    }
    Power& operator>>(int n);
};

Power& Power::operator>>(int n) {
    kick -= n;
    punch -= n;
    return *this;
}

int main() {

    int a, b;

    cout << "정수를 두 개 입력 : ";
    cin >> a >> b;

    Power p(a, b);

    p >> 3 >> 5 >> 6;

    p.show();

    return 0;
}