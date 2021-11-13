#include "graph.h"

ListNode::ListNode() {
    this->weight = 0;
    this->next = NULL;
}
ListNode::ListNode(int key)
{
    this->weight = 0;
    this->key = key;
    this->next = NULL;
}
ListNode::ListNode(int key, ListNode *next){
    this->weight = 0;
    this->key = key; 
    this->next = next; 
}

ListNode::ListNode(int key, ListNode *next, int weight){
    this->weight = weight;
    this->key = key;
    this->next = next;
}


bool Graph::dfsRec(int vertex, bool* visited, bool* recStack)
{
    if(!visited[vertex])
    {
        visited[vertex] = true;
        recStack[vertex] = true;

        ListNode* aux = adyList[vertex];
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
    this->adyList = new ListNode* [v+1];
    for (int i = 0; i <= v; i++)
    {
        this->adyList[i] = NULL;
    }
}

void Graph::insertEdge(int origin, int destination)
{
    ListNode* edge = new ListNode(destination, this->adyList[origin]);
    this->adyList[origin] = edge;
}

void Graph::insertEdge(int origin, int destination, int weight)
{
    ListNode* edge = new ListNode(destination, this->adyList[origin], weight);
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

void Graph::dfs(int vertex, bool* visited)
{
    if(!visited[vertex])
    {
        visited[vertex] = true;
        ListNode* aux = adyList[vertex];
        while(aux != NULL)
        {
            if(!visited[aux->key])
            {
                dfs(aux->key, visited);
            }
            aux = aux->next;
        }
    }
}

int Graph::conectedComponents()
{
    int count = 0;
    bool* visited = new bool[v+1];
    for (int i = 1; i <= v; i++)
        visited[i] = false;
 
    for (int i = 1; i <= v; i++) {
        if (visited[i] == false) {
            dfs(i, visited);
            count++;
        }
    }
    delete[] visited;
    return count;
}
