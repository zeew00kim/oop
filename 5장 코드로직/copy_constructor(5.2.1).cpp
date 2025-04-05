#include <iostream>
#include <cmath>
using namespace std;

// 숙쁠쁠 5-2 1번 문제 : 복사 생성자와 객체 복사
// 복사 생성자는 사용자가 명시적으로 클래스에 표시하지 않아도
// 컴파일러가 묵시적으로 자동 선언한다.
class Circle{
    int radius;
public:
    Circle() {
        radius = 0;
    }
    Circle(int radius) {
        this->radius = radius;
    }
    // 복사 생성자는 원본 생성자의 값을 그대로(const) 사용
    Circle(const Circle& circ) {
        this->radius = circ.radius;
        cout << "excution copy constructor & radius : " << radius << endl;
    }
    double getArea() {
        return 3.14 * pow(radius, 2);
    }
};

int main() {

    int radius;

    cout << "enter the radius value : ";
    cin >> radius;

    Circle origin(radius);
    Circle copified(origin); // 매개변수로 객체만 전달

    cout << "size of obj origin : " << origin.getArea() << endl;
    cout << "size of obj copified : " << copified.getArea() << endl;

    return 0;
}