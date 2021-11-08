#include "tads/graph.cpp"
#include "tads/minheap.cpp"
#include <iostream>
#define INF 9999999

using namespace std;

int* dijkstra(Graph* graph, int src)
{
    int* dist =  new int[graph->v+1];
    dist[src] = 0;
    Heap* heap = new Heap(graph->v);
    for (int i = 1; i <= graph->v; i++)
    {
        if(i != src)
        {
            dist[i] = INF;
        }
    }

    ListNode* v = graph->adyList[src];
    while(v)
    {
        dist[v->key]=v->weight;
        heap->add(v->weight,src,v->key);
        v = v->next;
    }

    while(!heap->isEmpty())
    {

        HeapNode* head = heap->poll();
        ListNode* v = graph->adyList[head->to];
        while(v)
        {
            int alt = dist[head->to] + v->weight;
            if(alt < dist[v->key])
            {
                dist[v->key] = alt;
                heap->add(alt,head->to,v->key);
            }
            v = v->next;
        }
    }
    return dist;

}

int main() {
    int V;
    cin >> V;
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
    for(int i = 1; i <= V2; i++) {
        int* distances = dijkstra(graph, i);
        for(int j = 1; j <= V2; j++) {
            if(distances[j] == INF || j == i){
                cout << -1 << endl;
            } else {
                cout << distances[j] << endl;
            }
        }
    }
    return 0;
}