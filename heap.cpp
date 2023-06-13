#include "heap.hpp"

bool MinHeap::empty() const
{
    return heap.empty();
}

void MinHeap::push(const HeapNode& node)
{
    heap.push_back(node);
    siftUp(heap.size() - 1);
}

HeapNode MinHeap::pop()
{
    HeapNode minNode = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);
    return minNode;
}

void MinHeap::siftUp(int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index].distance < heap[parent].distance)
    {
        swap(heap[index], heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void MinHeap::siftDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap.size() && heap[leftChild].distance < heap[smallest].distance)
    {
        smallest = leftChild;
    }

    if (rightChild < heap.size() && heap[rightChild].distance < heap[smallest].distance)
    {
        smallest = rightChild;
    }

    if (smallest != index)
    {
        swap(heap[index], heap[smallest]);
        siftDown(smallest);
    }
}

void Dijkstra(const vector<vector<pair<int, int>>>& graph, int startVertex, vector<int>& distances)
{
    int numVertices = graph.size();
    distances.resize(numVertices, numeric_limits<int>::max());
    distances[startVertex] = 0;

    MinHeap minHeap;
    minHeap.push(HeapNode(startVertex, 0));

    while (!minHeap.empty())
    {
        HeapNode minNode = minHeap.pop();
        int currentVertex = minNode.vertex;
        int currentDistance = minNode.distance;

        if (currentDistance > distances[currentVertex])
        {
            continue;
        }

        for (const auto& neighbor : graph[currentVertex])
        {
            int neighborVertex = neighbor.first;
            int neighborDistance = neighbor.second;
            int newDistance = currentDistance + neighborDistance;

            if (newDistance < distances[neighborVertex])
            {
                distances[neighborVertex] = newDistance;
                minHeap.push(HeapNode(neighborVertex, newDistance));
            }
        }
    }
}

vector<vector<pair<int, int>>> generateRandomGraph(int numVertices, double edgeDensity)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    vector<vector<pair<int, int>>> graph(numVertices);

    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = i + 1; j < numVertices; ++j)
        {
            if (dis(gen) < edgeDensity)
            {
                int weight = uniform_int_distribution<>(1, 100)(gen);
                graph[i].emplace_back(j, weight);
                graph[j].emplace_back(i, weight);
            }
        }
    }

    return graph;
}
