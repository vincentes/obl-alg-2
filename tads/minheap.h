class HeapNode
{
public:
    int cost;
    int from;
    int to;
    HeapNode(int cost, int from, int to);
    HeapNode();
    ~HeapNode();
    void removeKey();
    void updateKey();
};

/**
 * Min Heap
 */
class Heap
{
private:
    HeapNode** items;
    int capacity;
    int size;
    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parentIndex);
    int getParentIndex(int childIndex);

    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    bool hasParent(int index);

    int leftChild(int index);
    int rightChild(int index);
    int parent(int index);
    void swap(int indexOne, int indexTwo);
    void heapifyDown();
    void heapifyUp();
    void ensureExtraCapacity();

public:
    int peek();
    HeapNode* poll();
    void add(int cost, int from, int to);
    bool isEmpty();
    void print();

    Heap(int capacity);
    ~Heap();
};