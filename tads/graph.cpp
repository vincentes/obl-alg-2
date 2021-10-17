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
    if(v == 5) {
        v = v+1;
    }
    ListNode* aux = adyList[v];
    cout << "Scanning edges for v " << v << endl;
    if(v == 5) {
        cout << "--------" << endl;
        cout << "v 5 detected. Printing all edges." << endl;
        printEdges();
        cout << "--------" << endl;
    }
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
    cout << "inserting edge origin " << origin  << " dest " << destination << endl;
    ListNode* edge = new ListNode(destination, this->adyList[origin]);
    this->adyList[origin] = edge;
}

void Graph::printEdges() {
    for(int origin = 1; origin <= v; origin++) {
        cout << "edges of " << origin << endl;
        ListNode* aux = adyList[origin];
        if(!aux) {
            cout << "NO EDGES FOUND!!" << endl;
        }
        while(aux) {
            cout << aux->key << endl;
            aux = aux->next;
        }
    }
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
        cout << "Calculating possible paths for vertex " << i << endl;
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