// 7-3장 : ++ 연산자를 프렌드로 작성

#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this->kick = kick;
        this->punch = punch;
    }
    void show() {
        cout << "발차기 : " << kick << ", 주먹지르기 : " << punch << endl;
    }
    friend Power& operator--(Power& op);
    friend Power operator--(Power& op, int a);
};

Power& operator--(Power& op) {
    op.kick--;
    op.punch--;
    return op;
}

Power operator--(Power& op, int a) {
    Power temp = op;
    op.kick--;
    op.punch--;
    return temp;
}

int main() {

    int kick, punch;

    cout << "발차기와 펀치 값을 입력 : ";
    cin >> kick >> punch;

    Power a(kick, punch), b;

    cout << "[ 전치(--) 연산 이후 값 ]\n";

    b = --a;
    a.show(), b.show();

    cout << "[ 후치(--) 연산 이후 값 ]\n";

    b = a--;
    b.show();
    a.show();

    return 0;
}