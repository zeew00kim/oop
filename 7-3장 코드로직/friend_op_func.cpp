// 7-3장 연산자 함수 프렌드로 작성

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
        cout << "kick = " << kick << ", punch = " << punch << endl;
    }
    friend Power operator+(Power op1, Power op2);
    friend Power operator-(Power op1, Power op2);
};

Power operator+ (Power op1, Power op2) {
    Power temp;
    temp.kick = op1.kick + op2.kick;
    temp.punch = op1.punch + op2.punch;
    return temp;
}

Power operator-(Power op1, Power op2) {
    Power temp;
    if (op1.kick < op2.kick) {
        temp.kick = op2.kick - op1.kick;
    }
    else {
        temp.kick = op1.kick - op2.kick;
    }
    if (op1.punch < op2.punch) {
        temp.punch = op2.punch - op1.punch;
    }
    else {
        temp.punch = op1.punch - op2.punch;
    }

    return temp;
}

int main() {

    Power a(3, 5);
    Power b(4, 6);
    Power c, d;

    c = a + b;
    d = a - b;

    a.show();
    b.show();
    c.show();
    d.show();

    return 0;
}