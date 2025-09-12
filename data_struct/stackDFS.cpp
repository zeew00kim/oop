#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

template <class T>
class Stack {
    int top, size;
    vector<int> data;
public:
    Stack(int size = 5) {
        this->size = size;
        top = -1;
        data.resize(this->size);
    }
    bool is_empty() {
        return (top == -1) ? true : false;
    }
    bool is_full() {
        return (top == size - 1) ? true : false;
    }
    void push(T element) {
        if (is_full()) throw runtime_error("overflow error");
        data[++top] = element;
    }
    T pop() {
        if (is_empty()) throw runtime_error("underflow error");
        return data[top--];
    }
    T peek() {
        if (is_empty()) throw runtime_error("underflow error");
        return data[top];
    }
};

vector<vector<int>> graph;
vector<bool> visited;

void stackDFS(const int& start, const int& size) {
    Stack<int> stack(size);
    stack.push(start);

    while (!stack.is_empty()) {
        int node = stack.pop();
        if (visited[node]) continue;
        visited[node] = true;
        cout << node << " ";
        for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
            if (!visited[*it]) stack.push(*it);
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

    stackDFS(1, size + 1);

    return 0;
}