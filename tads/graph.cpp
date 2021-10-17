#include "graph.h"
#include <iostream>

ListNode::ListNode() {
    this->next = NULL;
}
ListNode::ListNode(int key)
{
    this->key = key;
    this->next = NULL;
}
ListNode::ListNode(int key, ListNode *next){
    this->key = key; 
    this->next = next; 
}
 

int Graph::dfsRec(int v, bool* visited) 
{
    cout << "dfsRec" << endl;
    int result = 0;
    cout << "v: " << v << endl;
    visited[v] = true;
    ListNode* aux = adyList[v];
    while(aux){
        cout << "aux->key: " << aux->key << endl;

        if (!visited[aux->key])
        {
            cout << "no visitado" << endl;
            result = dfsRec(aux->key, visited);
            if(result == 1){
                cout << "if(result == 1)" << endl;
                return result;
            }
            aux = aux->next;
        } else {
            cout << "set result 1" << endl;
            return 1;
        }
    }
    return result;
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

Graph::~Graph()
{

}

int Graph::hasCycle()
{
    cout << "hasCycle" << endl;
    int result = 0;
    for (int i = 1; i <= v; i++)
    {
        bool *vis = new bool[v + 1];
        for (int j = 1; j <= v; vis[j++] = false)
        ;
        result = dfsRec(i, vis);
        if(result == 1){
            return result;
        }
        delete[] vis;
    }
    return result;
}