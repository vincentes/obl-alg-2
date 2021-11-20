#include <string>
#include <cstring>

using namespace std;

class Edge
{
public:
  Edge *next;
  int key;
  int origin;
  int target;
  int weight;

  Edge();
  Edge(int key);
  Edge(int key, Edge *next);
  Edge(int key, Edge *next, int weight);
  Edge(int key, Edge *next, int weight, int source);
};


class Graph {

private:
    bool dfsRec(int v, bool* visited, bool* recStack);

public:
    int v;
    Edge** adyList;

    Graph(int v);

    void insertEdge(int origin, int destination);
    void insertEdge(int origin, int destination, int weight);

    ~Graph();

    int hasCycle();
};

