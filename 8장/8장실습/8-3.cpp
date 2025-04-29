#include <iostream>
#include <string>
using namespace std;

// 실습 8-3 : TV, WIdeTV, SmartTV 클스의 생성자 매개변수 전달

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

class WideTV : public TV {
	bool videoIN;
public:
	WideTV(int size, string videoIN) : TV(size) {
		if (videoIN == "true") {
			this->videoIN = true;
		}
		else {
			this->videoIN = false;
		}
	}
	bool getVideoln() {
		return videoIN;
	}
};

class SmartTV : public WideTV {
	string ipAddr;
public:
	SmartTV(string ipAddr, int size, string videoIN = "true") : WideTV(size, videoIN) {
		this->ipAddr = ipAddr;
	}
	string getIpAddr() {
		return ipAddr;
	}
};

int main() {

	string ip, videoIN;
	int size;

	do {
		cout << "size 값을 입력 : ";
		cin >> size;
		cin.ignore();

		cout << "ip 값을 입력 : ";
		getline(cin, ip);
	} while (size == 0 || ip == "");

	cout << "videoIn 값을 입력 : ";
	getline(cin, videoIN);

	SmartTV stv(ip, size, videoIN);
	cout << "size = " << stv.getSize() << endl;
	cout << "videoIn = " << boolalpha << stv.getVideoln() << endl;
	cout << "IP = " << stv.getIpAddr() << endl;

	return 0;
}