#include "stack.hpp"

Node::Node(int v, int d)
{
    vertex = v;
    distance = d;
    next = nullptr;
}

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

void Stack::push(int vertex, int distance)
{
    Node* newNode = new Node(vertex, distance);
    newNode->next = top;
    top = newNode;
}

void Stack::pop()
{
    if (isEmpty())
    {
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
}

Node* Stack::peek()
{
    return top;
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::dijkstra(vector<vector<pair<int, int>>>& graph, int startVertex, vector<int>& distances)
{
    int numVertices = graph.size();
    distances.resize(numVertices, numeric_limits<int>::max());
    distances[startVertex] = 0;

    push(startVertex, 0);

    while (!isEmpty())
    {
        Node* topNode = peek();
        int currentVertex = topNode->vertex;
        int currentDistance = topNode->distance;
        pop();

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
                push(neighborVertex, newDistance);
            }
        }
    }
}
