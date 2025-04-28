// 예제 8-3 : 생성자 매개 변수 전달 super() 묵시적/명시적

#include <iostream>
#include <string>
using namespace std;

class TV {
    int size;
public:
    TV() {
        size = 20;
    }
    TV(int size) {
        this->size = size;
    }
    int getSize() {
        return size;
    }
};

// wideTV는 TV의 자식 클래스
class WideTV : public TV {
    bool video;
public:
    WideTV(int size, bool video) : TV(size) {
        // 불리언 값을 대입 후 부모 클래스의 생성자 TV(size) 호출
        this->video = video;
    }
    bool getVideo() {
        return video;
    }
};

// SmartTV는 WideTV의 자식 클래스
class SmartTV : public WideTV {
    string ipAddr;
public:
    SmartTV(string ipAddr, int size) : WideTV(size, true) {
        // 주소 대입 후 명시적으로 부모 클래스의 생성자 WideTV(size, true) 호출
        this->ipAddr = ipAddr;
    }
    string getIpAddr() {
        return ipAddr;
    }
};

int main() {

    // boolalpha = bool 값을 true/false 값으로 출력되게 하는 조작자
    SmartTV stv("192.168.32.0", 60); // 마지막 자식 클래스 호출
    cout << "size = " << stv.getSize() << endl;
    cout << "video = " << boolalpha << stv.getVideo() << endl;
    cout << "IP = " << stv.getIpAddr() << endl;

    return 0;
}