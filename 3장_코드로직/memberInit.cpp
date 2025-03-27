#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point();
    Point(int a, int b);

    // this는 굳이 안써도 생성자가 알아서 해주긴 합니다!
    void setX(int a) {
        this->x = a; // main 함수에서 입력한 정수 a를 클래스의 맴버 x에 대입
    }
    void setY(int b) {
        this->y = b; // main 함수에서 입력한 정수 b를 클래스의 맴버 y에 대입
    }
    void show() {
        if (x != 20 && y != 30) {
            cout << "origin(x, y) : " << x << ", " << y << endl;
        }
        else {
            cout << "target(x, y) : " << x << ", " << y << endl;
        }
    }
};

Point::Point() : Point(x, y) {} // 위임 생성자

Point::Point(int a, int b) 
    : x(a), y(b) {} // 맴버 x, y 생성자 서두에 초기값 설정

int main() {

    int a, b;

    cout << "enter the integer value a & b : ";
    cin >> a >> b;

    Point origin; // 위임 생성자
    origin.setX(a);
    origin.setY(b);
    origin.show();

    Point target(20, 30); // 타겟 생성자
    target.show();

    return 0;
}