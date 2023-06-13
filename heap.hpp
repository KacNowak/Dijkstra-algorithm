#ifndef heap_hpp
#define heap_hpp

#include <iostream>
#include <vector>
#include <limits>
#include <random>

using namespace std;

struct HeapNode {
    int vertex;
    int distance;

    HeapNode(int v, int d) : vertex(v), distance(d) {}
};

class MinHeap {
private:
    vector<HeapNode> heap;

public:
    bool empty() const;
    void push(const HeapNode& node);
    HeapNode pop();

private:
    void siftUp(int index);
    void siftDown(int index);
};

void Dijkstra(const vector<vector<pair<int, int>>>& graph, int startVertex, vector<int>& distances);
vector<vector<pair<int, int>>> generateRandomGraph(int numVertices, double edgeDensity);

#endif // heap_hpp
