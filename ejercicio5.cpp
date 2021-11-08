#include "tads/graph.cpp"
#include "tads/minheap.cpp"
#include <iostream>
#define INF 9999999

using namespace std;

void addToMinHeap(Graph* graph, int src, Heap* minHeap)
{
    ListNode* aux = graph->adyList[src];
    while(aux)
    {
        cout << "adj a 0: " << aux->key << endl;
        minHeap->add(aux->weight,src,aux->key);
        aux = aux->next;
    }
}

int* dijkstra(Graph* graph, int src)
{
    // int vCount = 1;
    // int* distances = new int[graph->v];
    // for (int i = 0; i < graph->v; i++)
    // {
    //     distances[i] = -1;
    // }
    // Heap* minHeap = new Heap(graph->v);

    // addToMinHeap(graph, src, minHeap);
    // while(!minHeap->isEmpty() && vCount <= graph->v)
    // {
    //     HeapNode* head = minHeap->poll();
    //     vCount++;
    //     if(head->to != src && distances[head->to] == -1)
    //     {
    //         distances[head->to] = distances[head->from] + head->cost;
    //     }
    //     addToMinHeap(graph, head->to, minHeap);
    // }
    

    // return distances;

    int* dist =  new int[graph->v];
    int* prev =  new int[graph->v];
    dist[src] = 0;
    Heap* heap = new Heap(graph->v);
    for (int i = 0; i < graph->v; i++)
    {
        if(i != src)
        {
            dist[i] = INF;
            prev[i] = -1;
        }
    }

    ListNode* v = graph->adyList[src];
    while(v)
    {
        heap->add(v->weight,src,v->key);
        v = v->next;
    }

    while(!heap->isEmpty())
    {
        HeapNode* head = heap->poll();
        dist[head->to] = dist[head->from] + head->cost;

        ListNode* v = graph->adyList[head->to];
        while(v)
        {
            int alt = dist[head->to] + v->weight;
            if(alt < dist[head->to])
            {
                dist[head->to] = alt;
                prev[head->to] = head->from;
                heap->add(v->weight,head->to,v->key);
            }
            v = v->next;
        }
            
    }
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
    for(int i = 1; i < V2; i++) {
        cout << "Doing dijkstra for " << i << endl;
        int* distances = dijkstra(graph, i);
        cout << "Finished dijkstra for " << i << endl;
        for(int j = 1; j < V2; j++) {
            if(distances[j] == INF || j == i ){
                cout << -1 << endl;
            } else {
                cout << distances[j] << endl;
            }
        }
    }
    return 0;
}