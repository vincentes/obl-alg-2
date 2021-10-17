#include "tads/graph.cpp"
#include <iostream>
#include "string.h"

using namespace std;

int main() {
    int V;
    cin >> V;
    Graph* graph = new Graph(V);
    int E;
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        std::string origin;
        cin >> origin;
        std::string destination;
        cin >> destination;
        graph->insertEdge(stoi(origin), stoi(destination));
        // graph->printEdges();
    }    
    int result = graph->hasCycle();
    cout << result;
}