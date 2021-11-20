#include "graph.h"

Edge::Edge() {
    this->weight = 0;
    this->next = NULL;
}
Edge::Edge(int key)
{
    this->weight = 0;
    this->key = key;
    this->next = NULL;
}
Edge::Edge(int key, Edge *next){
    this->weight = 0;
    this->key = key; 
    this->next = next; 
}

Edge::Edge(int key, Edge *next, int weight){
    this->weight = weight;
    this->key = key;
    this->next = next;
}

Edge::Edge(int key, Edge *next, int weight, int source){
    this->weight = weight;
    this->key = key;
    this->next = next;
    this->origin = source;
}



bool Graph::dfsRec(int vertex, bool* visited, bool* recStack)
{
    if(!visited[vertex])
    {
        visited[vertex] = true;
        recStack[vertex] = true;

        Edge* aux = adyList[vertex];
        while(aux != NULL)
        {
            if(!visited[aux->key] && dfsRec(aux->key, visited, recStack))
            {
                return true;
            } else if (recStack[aux->key])
            {
                return true;
            }
            aux = aux->next;
        }
    }
    recStack[vertex] = false;
    return false;
}
    

Graph::Graph(int v) 
{
    this->v = v;
    this->adyList = new Edge* [v+1];
    for (int i = 0; i <= v; i++)
    {
        this->adyList[i] = NULL;
    }
}

void Graph::insertEdge(int origin, int destination)
{
    Edge* edge = new Edge(destination, this->adyList[origin]);
    this->adyList[origin] = edge;
}

void Graph::insertEdge(int origin, int destination, int weight)
{
    Edge* edge = new Edge(destination, this->adyList[origin], weight);
    this->adyList[origin] = edge;
}

Graph::~Graph()
{

}

int Graph::hasCycle()
{
    bool *visited = new bool[v+1];
    bool * recStack = new bool [v+1];
    for(int i = 0; i <= v; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i = 1; i <=v; i++)
    {
        if(dfsRec(i, visited, recStack))
        {
            return 1;
        }
    }
    return 0;
}



bool operator<(const Edge &a, const Edge &b)
{
  return a.weight < b.weight;
}

bool operator==(const Edge &a, const Edge &b)
{
  return a.weight == b.weight;
}

bool operator<=(const Edge &a, const Edge &b)
{
  return a == b || a < b;
}

bool operator>(const Edge &a, const Edge &b)
{
  return !(a <= b);
}

bool operator>=(const Edge &a, const Edge &b)
{
  return !(a < b);
}

bool operator!=(const Edge &a, const Edge &b)
{
  return !(a == b);
}

int fCompEdge(Edge *a, Edge *b)
{
  return a->weight - b->weight;
}
