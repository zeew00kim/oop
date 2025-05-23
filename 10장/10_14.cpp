#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime> 
using namespace std;

int main() {

	vector<int> v;
	int num;

	cout << "정수를 입력 : ";
	cin >> num;

	srand(time(NULL));

	for (int i = 0; i < num; i++) {
		int temp = rand() % 10 + 1;
		v.push_back(temp);
	}

	for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
	cout << endl;

	return 0;
}