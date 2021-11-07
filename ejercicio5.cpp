#include "tads/graph.cpp"
#include "tads/minheap.cpp"
#include <iostream>
#define INT_MAX 2147483647
using namespace std;
// The main function that calculates
// distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
int* dijkstra(Graph* graph, int src)
{

    cout << "\tInitializing variables" << endl;
    // Get the number of vertices in graph
    int V = graph->v;
    cout << "\tVertex count: " << V << endl;

    // dist values used to pick
    // minimum weight edge in cut
    int dist[V];

    // minHeap represents set E
    MinHeap* minHeap = new MinHeap(V);

    // cout << "\tInitializing min heap with all vertices and default dist value" << endl;

    // Initialize min heap with all
    // vertices. dist value of all vertices
    for (int v = 1; v < V; ++v)
    {
        // cout << "\t\tSetting dist[v] = INT_MAX" << endl;
        dist[v] = INT_MAX;
        // cout << "\t\tSetting array[v] = (new node)" << endl;

        minHeap->array[v] = new MinHeapNode(v, dist[v]);
        // cout << "\t\tSetting pos[v] = v" << endl;
        minHeap->pos[v] = v;
        // cout << "\t\tDONE Setting pos[v] = v" << endl;

    }

    // cout << "\tSetting variables to extract src vertex first" << endl;
    // Make dist value of src vertex
    // as 0 so that it is extracted first
    // cout << "\t\tInitialize minHeap array[src]" << endl;
    minHeap->array[src] =
            new MinHeapNode(src, dist[src]);
    // cout << "\t\tInitialize position[src] to src" << endl;
    minHeap->pos[src]   = src;
    // cout << "\t\tSet default dist[src] to zero" << endl;
    dist[src] = 0;
    // cout << "\tDecreasing key" << endl;
    minHeap->decreaseKey(minHeap, src, dist[src]);

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the followin loop,
    // min heap contains all nodes
    // whose shortest distance
    // is not yet finalized.
    while (!minHeap->isEmpty(minHeap))
    {
        cout << "\tENTERED WHILE LOOP" << endl;
        // Extract the vertex with
        // minimum distance value
        struct MinHeapNode* minHeapNode =
                minHeap->extractMin(minHeap);

        // Store the extracted vertex number
        int u = minHeapNode->v;

        // Traverse through all adjacent
        // vertices of u (the extracted
        // vertex) and update
        // their distance values
        ListNode* pCrawl =
                graph->adyList[u];
        while (pCrawl != NULL)
        {
            int v = pCrawl->key;

            // If shortest distance to v is
            // not finalized yet, and distance to v
            // through u is less than its
            // previously calculated distance
            if (minHeap->isInMinHeap(minHeap, v) &&
                dist[u] != INT_MAX &&
                pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;

                // update distance
                // value in min heap also
                minHeap->decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    for (int i = 0; i < V; ++i)
        printf("\t%d \t\t %d\n", i, dist[i]);

    return dist;
}

int main() {
    cout << "Getting input" << endl;
    int V;
    cin >> V;

    cout << "Initializing graph" << endl;
    Graph* graph = new Graph(V );
    int E;
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        std::string origin;
        cin >> origin;
        std::string destination;
        cin >> destination;
        std::string weight;
        cin >> weight;
        graph->insertEdge(stoi(origin), stoi(destination), stoi(weight));
    }

    int V2;
    cin >> V2;
    for(int i = 0; i < V2; i++) {
        cout << "Doing dijkstra for " << i << endl;
        int* distances = dijkstra(graph, i);
        cout << "Finished dijkstra for " << i << endl;

        for(int j = 0; j < V2; j++) {
            if(distances[j] == INT_MAX || i == j) {
                cout << "-1" << endl;
            } else {
                cout << distances[j] << endl;
            }
        }
    }
    return 0;
}