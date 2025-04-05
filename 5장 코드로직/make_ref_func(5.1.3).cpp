#include <iostream>
#include <cmath>
using namespace std;

// 숙쁠쁠 5-1 3번 문제 : 참조 매개 변수를 가진 함수 만들기
class Circle {
    int radius;
public:
    Circle() {
        radius = 0;
    }
    void setRadius(int radius) {
        this->radius = radius;
    }
    double getArea() {
        return 3.14 * pow(radius, 2);
    }
};

void insertRadius(Circle &c);

int main() {

    Circle donut;
    insertRadius(donut);

    cout << "size of donut : " << donut.getArea() << endl;

    return 0;
}

void insertRadius(Circle &c) {

    int rad;

    do {
        cout << "enter the radius value : ";
        cin >> rad;
        if (rad <= 0) {
            cout << "this value is non-positive integer. retry it...\n";
        }
    } while (rad <= 0);

    c.setRadius(rad);
}