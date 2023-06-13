#ifndef stack_hpp
#define stack_hpp

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Node {
public:
    int vertex;
    int distance;
    Node* next;

    Node(int v, int d);
};

class Stack {
private:
    Node* top;

public:
    Stack();
    ~Stack();
    void push(int vertex, int distance);
    void pop();
    Node* peek();
    bool isEmpty();
    void dijkstra(vector<vector<pair<int, int>>>& graph, int startVertex, vector<int>& distances);
};

#endif // stack_hpp
