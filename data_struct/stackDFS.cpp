#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

template <class T>
class Queue {
    int front, rear, size;
    vector<T> data;
public:
    Queue(int size = 5) {
        this->size = size;
        front = rear = 0;
        data.resize(this->size);
    }
    bool is_empty() {
        return (front == rear) ? true : false;
    }
    bool is_full() {
        return (front == (rear + 1) % size) ? true : false;
    }
    void euqueue(T element) {
        if (is_full()) throw runtima_error("overflow error");
        data[rear] = element;
        rear = (rear + 1) % size;
    }
    T dequeue() {
        if (is_empty()) throw runtime_error("underflow error");
        T temp = data[front];
        front = (front + 1) % size;
        return temp;
    }
    T peek() {
        if (is_empty()) throw runtime_error("underflow error");
        return data[front];
    }
};

vector<vector<int>> graph;
vector<bool> visited;

void queueBFS(const int& start, const int& size) {
    Queue<int> queue(size);
    queue.euqueue(start);

    while (!queue.is_empty()) {
        int node = queue.dequeue();
        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
        }
        for (auto it = graph[node].begin(); it != graph[node].end(); ++it) {
            if (!visited[*it]) {
                queue.euqueue(*it);
            }
        }
    }
}
int main() {

    int size = 6;

    graph.resize(size + 1);
    visited.resize(size + 1, false);

    graph[1] = { 2, 3 };
    graph[2] = { 1, 4, 5 };
    graph[3] = { 1 };
    graph[4] = { 2 };
    graph[5] = { 2, 6 };
    graph[6] = { 5 };

    queueBFS(1, size + 1);

    return 0;
}