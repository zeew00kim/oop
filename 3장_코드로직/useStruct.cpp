#include <iostream>
#include <cmath>
using namespace std;

struct Circle {
private:
    int radius;
public:
    Circle(int r) {
        radius = r;
    }
    double getArea() {
        return 3.14 * pow(radius, 2);
    }
};

int main() {

    int rad;

    cout << "enter the radius : ";
    cin >> rad;
    Circle circ(rad);
    cout << "size of circ : " << circ.getArea() << endl;

    return 0;
}