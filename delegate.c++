#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point();
    Point(int a, int b);
    void showValue() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

Point::Point() : Point(0, 0) {}

Point::Point(int a, int b)
    : x(a), y(b) {}

int main() {

    Point origin;
    origin.showValue();
    Point target(10, 20);
    target.showValue();

    return 0;
}