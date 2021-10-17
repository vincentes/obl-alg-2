#include <string>
#include <cstring>

using namespace std;

class ListNode
{
public:
  ListNode *next;
  int key;

  ListNode();
  ListNode(int key);
  ListNode(int key, ListNode *next);
};


class Graph {

private:
    ListNode** adyList;
    int v;
    int dfsRec(int v, bool* visited);

public:
    Graph(int v);

    void insertEdge(int origin, int destination);

    ~Graph();

    int hasCycle();
};