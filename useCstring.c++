#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char password[11];
    
    cout << "[ if you wand program off, enter the password ]\n";
    
    while(true) {
        cout << "P/W : ";
        cin >> password;
        if (strcmp(password, "zeew00") == 0) {
            cout << "program off...\n";
            break;
        }
        else {
            cout << "password is uncorrected...\n";
        }
    }

    return 0;
}