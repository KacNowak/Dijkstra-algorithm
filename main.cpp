#include "stack.hpp"
#include "heap.hpp"
#include <chrono>

int main() {
    int numVertices = 5000;
    double edgeDensity = 0.3;

    vector<vector<pair<int, int>>> graph = generateRandomGraph(numVertices, edgeDensity);

    Stack s1;
    int startVertex = 0;
    vector<int> distances;

    auto start = chrono::high_resolution_clock::now();
    //s1.dijkstra(graph, startVertex, distances); //Stos
    Dijkstra(graph, startVertex, distances); //Kopiec
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //cout << "Dijkstra na stosie: " << duration.count() << " mikrosekund" << endl; //Stos
    cout << "Dijkstra na kopcu: " << duration.count() << " mikrosekund" << endl; //Kopiec

    //najkrotsze odleglosci
    //for (int i = 0; i < numVertices; ++i) {
        //cout << "Distance from " << startVertex << " to " << i << ": " << distances[i] << endl;
    //}

    return 0;
}
