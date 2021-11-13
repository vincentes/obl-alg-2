#include <string>
#include <cstring>

using namespace std;

class ListNode
{
public:
  ListNode *next;
  int key;
  int weight;

  ListNode();
  ListNode(int key);
  ListNode(int key, ListNode *next);
  ListNode(int key, ListNode *next, int weight);
};


class Graph {

private:
    bool dfsRec(int v, bool* visited, bool* recStack);
    void dfs(int v, bool* visited);

public:
    int v;
    ListNode** adyList;

    Graph(int v);

    void insertEdge(int origin, int destination);
    void insertEdge(int origin, int destination, int weight);

    ~Graph();

    int hasCycle();
    int conectedComponents();
};