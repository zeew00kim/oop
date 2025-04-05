#include <iostream>
#include <ctime>
using namespace std;

// 숙쁠쁠 5-1 2 번째 문제 : 참조 매개변수로 평균 리턴하기
void selectionSort(int *arr, int size);
bool getAvg(int* arr, int size, double& avg);

int main() {

    int num;
    double avg;

    srand(time(NULL));

    cout << "enter the size of array : ";
    cin >> num;

    int* arr = new int[num];

    for (int i = 0; i < num; i++) {
        arr[i] = rand() % 10 + 1;
        cout << arr[i] << " ";
    }

    cout << endl;

    selectionSort(arr, num);

    if (getAvg(arr, num, avg)) {
        cout << "average : " << avg << endl;
    }

    delete[] arr;

    return 0;
}

void selectionSort(int *arr, int size) {

    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    int i = 0;

    while (i < size) {
        cout << arr[i] << " ";
        i++;
    }

    cout << endl;
}

bool getAvg(int* arr, int size, double& avg) {

    int sum = 0;

    if (size < 0) {
        return false;
    }
    else {
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
    }

    avg = double(sum) / size;

    return true;
}