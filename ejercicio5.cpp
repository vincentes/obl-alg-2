#include "tads/graph.cpp"
#include "tads/minheap.cpp"
#include <fstream>
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

    Edge* v = graph->adyList[src];
    while(v)
    {
        dist[v->key]=v->weight;
        heap->add(v->weight,src,v->key);
        v = v->next;
    }

    while(!heap->isEmpty())
    {
        HeapNode* head = heap->poll();
        Edge* v = graph->adyList[head->to];
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
    delete heap;
    return dist;
}

int main() {
    // // IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
    // ifstream myFile("test-cases/ejercicio5/dijk10e2.in.txt");
    // cin.rdbuf(myFile.rdbuf());
    // // Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
    // ofstream myFile2("test-cases/ejercicio5/dijk10e2.mine.txt");
    // cout.rdbuf(myFile2.rdbuf());

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
    }

    int V2;
    cin >> V2;
    for(int i = 0; i < V2; i++) {
        int src;
        cin >> src;
        int* distances = dijkstra(graph, src);
        for(int j = 1; j <= V; j++) {
            if(distances[j] == INF || j == src){
                cout << -1 << endl;
            } else {
                cout << distances[j] << endl;
            }
        }
        delete[] distances;
    }
    return 0;
}