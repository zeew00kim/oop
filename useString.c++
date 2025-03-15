#include <iostream>
#include <string>
using namespace std;

int main() {

    string carName("sportage");
    string carType("suv");
    string type;

    while(true) {
        cout << "enter the type of car\n";
        cout << "hint : car name is sportage\n";
        getline(cin, type);
        if (type == carType) {
            cout << "this car is kia's middle size suv\n";
            break;
        }
        else {
            cout << "uncorrect, retry it...\n";
        }
    }

    return 0;
}