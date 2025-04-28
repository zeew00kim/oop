// 예제 8-1 : Point 클래스를 상속 받는 ColorPoint 클래스 만들기

#include <iostream>
#include <string>
using namespace std;

// 2차원 평면에서 한 점을 표현하는 클래스
class Point {
    int x, y; // showPoint() 함수만 접근 가능
public:
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void showPoint() {
        cout << "x : " << x << ", y : " << y << endl;
    }
};

// 2차원 평면에서 Color의 점을 표현하는 클래스
class ColorPoint : public Point {
    string color;
public:
    void setColor(string color) {
        this->color = color;
    }
    void showColorPoint();
};

void ColorPoint::showColorPoint() {
    cout << color << endl;
    showPoint(); // 부모 클래스의 showPoint() 호출
}

int main() {

    Point p;
    ColorPoint cp;
    cp.set(3, 4); // 기본 클래스의 맴버를 호출
    cp.setColor("RED"); // 파생 클래스의 맴버를 호출
    cp.showColorPoint();

    return 0;
}