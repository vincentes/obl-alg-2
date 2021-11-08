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
    for (int i = 0; i <= graph->v; i++)
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
        // cout << "SRC ADY set dist[" << v->key << "] = " << v->weight << endl;
        heap->add(v->weight,src,v->key);
        v = v->next;
    }

    while(!heap->isEmpty())
    {

        HeapNode* head = heap->poll();
        ListNode* aux = graph->adyList[head->to];
        while(aux)
        {
            // cout << head->to << " " << aux->key << " " << aux->weight << endl;
            aux = aux->next;
        }
        ListNode* v = graph->adyList[head->to];
        int count = 0;
        while(v)
        {   
            // cout << "count: " << count << endl;
            // cout << "head->to " << head->to << endl;
            // cout << "v " << v->key << " ady of " << head->to << " v->weight " << v->weight << endl;
            // cout << "dist[head->to] " << dist[head->to] << " v->weight " << v->weight << " dist[" << v->key << "] " << dist[v->key] << endl;
            int alt = dist[head->to] + v->weight;
            if(alt < dist[v->key])
            {
                dist[v->key] = alt;
                // cout << "set dist[" << v->key << "] = " << alt << endl;
                // cout << head->to << " -> head->to before add" << endl;
                heap->add(alt,head->to,v->key);
                // cout << head->to << " -> head->to after add" << endl;
            }
            v = v->next;
            count++;
        }
    }
    delete heap;
    return dist;

}

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
        std::string weight;
        cin >> weight;
        graph->insertEdge(stoi(origin), stoi(destination), stoi(weight));
        // cout << origin << " " << destination << " " << weight << endl;
    }

    int V2;
    cin >> V2;
    // cout << "V2: " << V2 << endl;
    for(int i = 1; i <= V2; i++) {
        // cout << "src: " << i << endl;
        int* distances = dijkstra(graph, i);
        for(int j = 1; j <= V; j++) {
            if(distances[j] == INF || j == i){
                cout << -1 << endl;
            } else {
                cout << distances[j] << endl;
            }
        }
        delete[] distances;
    }
    return 0;
}