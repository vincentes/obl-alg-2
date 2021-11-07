class MinHeapNode
{
public:
    int  v;
    int dist;
    MinHeapNode(int v, int dist);
};



// ure to represent a min heap
class MinHeap
{

public:
    MinHeapNode **array;
    // Number of heap nodes present currently
    int size;

    // Capacity of min heap
    int capacity;

    // This is needed for decreaseKey()
    int *pos;

    MinHeap(int capacity);
    MinHeapNode* newMinHeapNode(int v, int dist);
    MinHeap* createMinHeap(int capacity);
    int isEmpty(MinHeap* minHeap);
    MinHeapNode* extractMin(MinHeap* minHeap);
    bool isInMinHeap(MinHeap *minHeap, int v);
    void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b);
    void minHeapify(MinHeap* minHeap, int idx);
    void decreaseKey(MinHeap* minHeap, int v, int dist);
};


