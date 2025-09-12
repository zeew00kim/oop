#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

ostream& operator << (ostream& os, vector<int>& v) {
	int size;
	os << "벡터 배열의 크기를 지정 -> ";
	cin >> size;
	v.resize(size);
	return os;
}

template <class T>
void merge(vector<T>& p, int left, int mid, int right) {
	vector<T> temp(p.size(), 0);
	int i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right) {
		if (p[i] < p[j]) {
			temp[k++] = p[i++];
		}
		else temp[k++] = p[j++];
	}
	while (i <= mid) temp[k++] = p[i++];
	while (j <= right) temp[k++] = p[j++];
	for (i = left; i <= right; ++i) {
		p[i] = temp[i];
	}
}

void mergeSort(vector<int>& p, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(p, left, mid);
		mergeSort(p, mid + 1, right);
		merge(p, left, mid, right);
	}
}

int BST(vector<int>& p, int left, int right, int target) {
	if (left <= right) {
		int mid = (left + right) / 2;
		if (p[mid] == target) return mid;
		else if (p[mid] > target) return BST(p, left, mid - 1, target);
		else return BST(p, mid + 1, right, target);
	}
}

int main() {

	vector<int> arr;
	int target;
	
	srand(time(NULL));

	cout << arr;

	for (int i = 0; i < arr.size(); i++) {
		arr[i] = rand() % 100 + 1;
	}

	mergeSort(arr, 0, arr.size() - 1);

	cout << "result of mergeSort -> ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "문자열에서 찾을 정수 값 : ";
	cin >> target;

	cout << "이진 탐색을 통해 정수 " << target << "을 조회한 결과 ( ";
	cout << BST(arr, 0, arr.size() - 1, target) << " 번째 인덱스에서 발견되었습니다. )" << endl;

	return 0;
}