#include <iostream>
#include <cmath>
using namespace std;

class Circle {
public:
    int radius;
    static int destCnt;
    Circle() {
        do {
            cout << "enter the value of radius : ";
            cin >> radius;
            if (radius < 0) {
                cout << "you enter the minus value...\n";
            }
        } while (radius < 0);
        cout << "size of radius : " << radius << endl;
    }
    Circle(int radius) {
        this->radius = radius;
        cout << "size of radius : " << radius << endl;
    }
    ~Circle() {
        destCnt++;
        cout << "destruct Circle's obj (" << destCnt << ")\n";
    }
    double getArea() {
        return 3.14 * pow(radius, 2);
    }
};

int Circle::destCnt = 0;

Circle globalPizza(1000);
Circle globalDonut(2000);

void useFunc(int* rad) {

    int r = *rad;
    Circle funcPizza(r);
    Circle funcDonut(r);
}

int main() {

    int rad;
    cout << "enter the radius : ";
    cin >> rad;

    Circle localPizza;
    Circle localDonut(rad);
    useFunc(&rad);

    return 0;
}